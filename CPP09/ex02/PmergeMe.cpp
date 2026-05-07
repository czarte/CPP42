//
// PmergeMe.cpp — non-template implementations:
//   - g_comparisons definition
//   - Jacobsthal helper
//   - argv parsing for both std::deque<int> and std::list<int>
//   - Driver functions that time the sort and print results
//

#include "PmergeMe.hpp"
#include <set>
#include <sstream>

unsigned long g_comparisons = 0;

// -------------------------------------------------------------------------
// Jacobsthal sequence
// -------------------------------------------------------------------------
// J_0 = 0, J_1 = 1, J_n = J_{n-1} + 2 * J_{n-2}
// -> 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, ...
std::vector<size_t> jacobsthalUpTo(size_t bound) {
	std::vector<size_t> jv;
	jv.push_back(0);
	jv.push_back(1);
	while (jv.back() <= bound) {
		const size_t n  = jv.size();
		const size_t nv = jv[n - 1] + 2 * jv[n - 2];
		jv.push_back(nv);
	}
	// Add one more so callers can safely look at jv[k] when jv[k-1] <= bound.
	const size_t n  = jv.size();
	const size_t nv = jv[n - 1] + 2 * jv[n - 2];
	jv.push_back(nv);
	return jv;
}

// -------------------------------------------------------------------------
// Argv parsing — accepts a sequence of non-negative integers, rejects
// duplicates and malformed input.
// -------------------------------------------------------------------------
static bool parseInt(const char* s, int& out) {
	if (!s || !*s) return false;
	// Disallow leading sign and whitespace; only digits accepted.
	for (const char* p = s; *p; ++p)
		if (*p < '0' || *p > '9') return false;
	// Use strtol to detect overflow.
	char* endp = 0;
	long v = std::strtol(s, &endp, 10);
	if (endp == s || *endp != '\0') return false;
	if (v < 0 || v > INT_MAX) return false;
	out = static_cast<int>(v);
	return true;
}

template <typename Container>
static void parseArgvImpl(int argc, char** argv, Container& out) {
	out.clear();
	std::set<int> seen;
	for (int i = 1; i < argc; ++i) {
		int v;
		if (!parseInt(argv[i], v))
			throw std::runtime_error("Error");
		if (!seen.insert(v).second)
			throw std::runtime_error("Error");  // duplicate
		out.push_back(v);
	}
}

void PmergeMe::parseArgv(int argc, char** argv, std::deque<int>& out) {
	parseArgvImpl(argc, argv, out);
}

void PmergeMe::parseArgv(int argc, char** argv, std::list<int>& out) {
	parseArgvImpl(argc, argv, out);
}

// -------------------------------------------------------------------------
// Pretty-printing
// -------------------------------------------------------------------------
void PmergeMe::printInput(int argc, char** argv) {
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

// -------------------------------------------------------------------------
// Drivers — parse, sort, time, print.
// -------------------------------------------------------------------------
void PmergeMe::runDeque(int argc, char** argv) {
	std::deque<int> seq;
	parseArgv(argc, argv, seq);

	g_comparisons = 0;
	const clock_t t0 = clock();
	fordJohnsonSort(seq, 1);
	const clock_t t1 = clock();
	const double us = static_cast<double>(t1 - t0) * 1e6
	                / static_cast<double>(CLOCKS_PER_SEC);

	printOutput(seq);
	std::cout << "Time to process a range of " << seq.size()
	          << " elements with std::deque : "
	          << us << " us" << std::endl;
	std::cout << "Number of comparisons (deque): " << g_comparisons << std::endl;
}

void PmergeMe::runList(int argc, char** argv) {
	std::list<int> seq;
	parseArgv(argc, argv, seq);

	g_comparisons = 0;
	const clock_t t0 = clock();
	fordJohnsonSort(seq, 1);
	const clock_t t1 = clock();
	const double us = static_cast<double>(t1 - t0) * 1e6
	                / static_cast<double>(CLOCKS_PER_SEC);

	printOutput(seq);
	std::cout << "Time to process a range of " << seq.size()
	          << " elements with std::list  : "
	          << us << " us" << std::endl;
	std::cout << "Number of comparisons: " << g_comparisons << std::endl;
}
