//
// Ford-Johnson (merge-insertion) sort, level-based recursive implementation.
// Templated on the container type so it works for std::deque<int> and
// std::list<int> using the same algorithm.
//

#ifndef CPP42_PMERGEME_HPP
#define CPP42_PMERGEME_HPP

#include <list>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <climits>
#include <ctime>
#include <cstdlib>

extern unsigned long g_comparisons;

// -------------------------------------------------------------------------
// PmergeMe — public API: parse input, run Ford-Johnson, print results.
// -------------------------------------------------------------------------
class PmergeMe {
public:
	// Driver functions for the two required containers.
	static void runDeque(int argc, char** argv);
	static void runList(int argc, char** argv);

	// Helpers.
	static void printInput(int argc, char** argv);
	static void parseArgv(int argc, char** argv, std::deque<int>& out);
	static void parseArgv(int argc, char** argv, std::list<int>& out);

	// Templated print.
	template <typename Container>
	static void printOutput(const Container& seq) {
		std::cout << "After: ";
		for (typename Container::const_iterator it = seq.begin();
			 it != seq.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
};

// -------------------------------------------------------------------------
// Ford-Johnson algorithm internals (templated, header-only).
// -------------------------------------------------------------------------

// Build Jacobsthal numbers up to and beyond `bound`.
// Returns a sequence starting J_0=0, J_1=1, J_2=1, J_3=3, J_4=5, J_5=11, ...
std::vector<size_t> jacobsthalUpTo(size_t bound);

// std::advance + return — emulates C++11 std::next for iterators.
template <typename It>
inline It advanced(It it, std::ptrdiff_t n) {
	std::advance(it, n);
	return it;
}

// Snapshot the first `num_groups * group_size` elements of `seq` as a
// vector of groups (vector of vector<int>), and store any trailing
// elements (those beyond num_groups full groups) in `remainder`.
template <typename Container>
void snapshotGroups(Container& seq, size_t group_size, size_t num_groups,
					std::vector< std::vector<int> >& groups,
					std::vector<int>& remainder)
{
	groups.clear();
	remainder.clear();
	groups.reserve(num_groups);
	typename Container::iterator it = seq.begin();
	for (size_t g = 0; g < num_groups; ++g) {
		std::vector<int> gv;
		gv.reserve(group_size);
		for (size_t k = 0; k < group_size; ++k) {
			gv.push_back(*it);
			++it;
		}
		groups.push_back(gv);
	}
	while (it != seq.end()) {
		remainder.push_back(*it);
		++it;
	}
}

// Write groups (in `main_chain` order) followed by `remainder` back into seq.
template <typename Container>
void writeBackGroups(Container& seq,
					 const std::vector< std::vector<int> >& groups,
					 const std::vector<size_t>& main_chain,
					 const std::vector<int>& remainder,
					 size_t group_size)
{
	seq.clear();
	for (size_t i = 0; i < main_chain.size(); ++i) {
		const std::vector<int>& g = groups[main_chain[i]];
		for (size_t k = 0; k < group_size; ++k)
			seq.push_back(g[k]);
	}
	for (size_t i = 0; i < remainder.size(); ++i)
		seq.push_back(remainder[i]);
}

// Phase 1 at this level: pair adjacent groups, compare leaders, swap groups
// in-place so the smaller-leader group ("loser-group") comes first within
// each meta-pair.
//
// Comparisons counted: one per meta-pair.
template <typename Container>
void phase1Pair(Container& seq, size_t group_size, size_t num_groups) {
	if (num_groups < 2) return;

	typename Container::iterator group_start = seq.begin();
	for (size_t g = 0; g + 1 < num_groups; g += 2) {
		typename Container::iterator leader_a =
			advanced(group_start, static_cast<std::ptrdiff_t>(group_size) - 1);
		typename Container::iterator b_start = advanced(leader_a, 1);
		typename Container::iterator leader_b =
			advanced(b_start, static_cast<std::ptrdiff_t>(group_size) - 1);

		++g_comparisons;
		if (*leader_a > *leader_b) {
			// In-place swap of two adjacent groups (value-by-value).
			// Works for both std::list (no random access) and std::deque.
			std::vector<int> bufA(group_size), bufB(group_size);
			typename Container::iterator it = group_start;
			for (size_t k = 0; k < group_size; ++k) { bufA[k] = *it; ++it; }
			for (size_t k = 0; k < group_size; ++k) { bufB[k] = *it; ++it; }
			it = group_start;
			for (size_t k = 0; k < group_size; ++k) { *it = bufB[k]; ++it; }
			for (size_t k = 0; k < group_size; ++k) { *it = bufA[k]; ++it; }
		}
		// Advance to start of next meta-pair.
		std::advance(group_start, static_cast<std::ptrdiff_t>(2 * group_size));
	}
}

// Phase 3 at this level: insert the loser-groups (the first group within each
// meta-pair) into the main chain via Jacobsthal-ordered binary search on
// group leaders. Handles a stray (unpaired tail group) at the end.
//
// Comparisons counted: one per binary-search step.
template <typename Container>
void phase3Insert(Container& seq, size_t group_size, size_t num_groups) {
	if (num_groups < 2) return;

	const size_t num_pairs = num_groups / 2;
	const bool has_stray = (num_groups % 2 != 0);

	// 1) Snapshot all groups + any remainder into vectors.
	std::vector< std::vector<int> > groups;
	std::vector<int> remainder;
	snapshotGroups<Container>(seq, group_size, num_groups, groups, remainder);

	// Group indexing in `groups`:
	//   pair p (0-indexed) has loser at group 2*p, winner at group 2*p + 1.
	//   stray (if any) is at group num_groups - 1.

	// 2) Initial main chain = [b_1, a_1, a_2, ..., a_{num_pairs}].
	//    (b_1 is the loser of pair 0 — already < a_1, so it goes first "for free".)
	std::vector<size_t> main_chain;
	main_chain.reserve(num_groups);
	main_chain.push_back(0);                  // b_1 (loser of pair 0)
	for (size_t p = 0; p < num_pairs; ++p)
		main_chain.push_back(2 * p + 1);      // a_{p+1} (winner of pair p)

	// winner_pos_in_chain[p] = current index of winner-of-pair-p in main_chain.
	std::vector<size_t> winner_pos_in_chain(num_pairs);
	for (size_t p = 0; p < num_pairs; ++p)
		winner_pos_in_chain[p] = p + 1;

	// 3) Build pend insertion order in Jacobsthal blocks.
	//    Pend index k (1-based):
	//      - k in [1, num_pairs - 1] -> regular loser b_{k+1} = loser of pair k
	//        (its bound is the position of the corresponding winner a_{k+1}).
	//      - k == num_pairs (only if has_stray) -> the stray group
	//        (its bound is the full main chain — no corresponding winner).
	//    Total pend = (num_pairs - 1) + (has_stray ? 1 : 0).
	//    For Jacobsthal block k (k=3,4,5,...):
	//        insert pend[J_k - 1], pend[J_k - 2], ..., pend[J_{k-1}].
	const size_t total_pend = (num_pairs - 1) + (has_stray ? 1 : 0);
	std::vector<size_t> jac = jacobsthalUpTo(total_pend + 2);

	std::vector<size_t> insertion_order;
	insertion_order.reserve(total_pend);
	for (size_t k = 3; k < jac.size(); ++k) {
		size_t lo = jac[k - 1];
		if (lo > total_pend) break;
		size_t hi = jac[k] - 1;
		if (hi > total_pend) hi = total_pend;
		// Insert in descending order: hi, hi-1, ..., lo.
		for (size_t pi = hi; pi >= lo; --pi) {
			insertion_order.push_back(pi);
			if (pi == 0) break;  // safety; in practice lo >= 1
		}
	}

	// 4) Perform pend insertions in Jacobsthal order (stray is included).
	for (size_t i = 0; i < insertion_order.size(); ++i) {
		const size_t pend_idx = insertion_order[i];
		size_t group_idx;
		size_t upper_bound_pos;
		if (pend_idx < num_pairs) {
			// Regular loser: pend[k] = loser of pair k.
			group_idx = 2 * pend_idx;
			upper_bound_pos = winner_pos_in_chain[pend_idx];
		} else {
			// Stray (pend_idx == num_pairs, only when has_stray is true).
			group_idx = num_groups - 1;
			upper_bound_pos = main_chain.size();
		}

		// Binary search by group-leader value in main_chain[0, upper_bound_pos).
		const int key = groups[group_idx].back();
		size_t lo = 0;
		size_t hi = upper_bound_pos;
		while (lo < hi) {
			const size_t mid = lo + (hi - lo) / 2;
			const int mid_leader = groups[main_chain[mid]].back();
			++g_comparisons;
			if (mid_leader < key) lo = mid + 1;
			else                  hi = mid;
		}
		main_chain.insert(main_chain.begin() + lo, group_idx);
		// Shift recorded winner positions that were at or beyond `lo`.
		for (size_t p = 0; p < num_pairs; ++p)
			if (winner_pos_in_chain[p] >= lo) ++winner_pos_in_chain[p];
	}

	// 5) Write groups back to seq in main_chain order, then append remainder.
	writeBackGroups<Container>(seq, groups, main_chain, remainder, group_size);
}

// Recursive Ford-Johnson sort. Top-level call: fordJohnsonSort(seq, 1).
//
// Each level pairs adjacent groups of size `group_size` and recursively
// sorts the meta-pairs (group_size doubled). On the way back, loser-groups
// are inserted into the main chain via Jacobsthal-ordered binary search.
template <typename Container>
void fordJohnsonSort(Container& seq, size_t group_size) {
	const size_t num_groups = seq.size() / group_size;
	if (num_groups < 2) return;

	phase1Pair<Container>(seq, group_size, num_groups);
	fordJohnsonSort<Container>(seq, group_size * 2);
	phase3Insert<Container>(seq, group_size, num_groups);
}

#endif  // CPP42_PMERGEME_HPP
