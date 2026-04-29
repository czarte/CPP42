//
// Created by Vojtěch Parkán on 26.04.2026.
//

#ifndef CPP42_PMERGEME_HPP
#define CPP42_PMERGEME_HPP

#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <ctime>
#include <vector>

#define JAC 33

class PmergeMe {
public:
	static bool compare_size(std::pair<int, int> a, std::pair<int, int> b);
	static size_t jacobsthal_recursion(int n);
	static std::vector<size_t> jacobsthal();
	static void printInput(char ** argv, int argc);
	static void print_pairs(std::list<std::pair<int, int> > list_pairs);
};

void mergeSort(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end, size_t size);
void mergeSort(std::deque<std::pair<int, int> >::iterator start, std::deque<std::pair<int, int> >::iterator end, size_t size);

template<typename T>
void createPairs(T * list_pairs, char ** input, int * additional_value) {
	int i = 1;
	while (input[i]) {
		int x = std::atoi(input[i]);
		if (x < 0)
			throw std::out_of_range("Only positive values");
		if (input[i] && input[i + 1]) {
			int y = std::atoi(input[i + 1]);
			if (y < 0)
				throw std::out_of_range("Only positive values");
			std::pair<int, int> temp(x, y);
			list_pairs->push_back(temp);
			i += 2;
		} else {
			*additional_value = x;
			i++;
		}

	}
}
template<typename T, typename IT>
void sortPairs(T * list_pairs, IT it) {
	for (it = list_pairs->begin(); it != list_pairs->end(); ++it) {
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

template<typename M, typename T, typename IT>
void initResult(M * results, T list_pairs, IT it) {
	for (it = list_pairs.begin(); it != list_pairs.end(); ++it) {
		results->push_back(it->second);
	}
	if (!list_pairs.empty()) {
		results->push_front(list_pairs.begin()->first);
	}
}
template<typename M, typename I, typename IT>
void binary_search_insertion(M *results, I end, int val, IT insert_pos) {
	insert_pos = std::lower_bound(results->begin(), end, val);
	results->insert(insert_pos, val);
/*
	std::cout << "result current value: " << val << " : end iterator " << *end << " place to insert: " << *(insert_pos--) << std::endl;
	for (std::list<int>::iterator it = results->begin(); it != results->end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
*/
}
template<typename T, typename M, typename I, typename JI, typename SD, typename IT>
void insertIntoResult(T list_pairs, M * results, int additional_value, I pair_iterator, JI last_jacobsthal, SD slice_delimiter, IT insert_pos) {
	std::vector<size_t> jabobsthal = PmergeMe::jacobsthal();
	//size_t jabobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	int jacobsthal_index = 1;

	last_jacobsthal = list_pairs.begin();

	while (jabobsthal[jacobsthal_index] <= list_pairs.size()) {
		pair_iterator = list_pairs.begin();
		std::advance(pair_iterator, jabobsthal[jacobsthal_index] - 1);
		last_jacobsthal = pair_iterator;

		int insertion_index = 0;
		while (jabobsthal[jacobsthal_index] - insertion_index > jabobsthal[jacobsthal_index - 1]) {
			slice_delimiter = std::find(results->begin(), results->end(), pair_iterator->second);
			binary_search_insertion(results, slice_delimiter, pair_iterator->first, insert_pos);
			pair_iterator--;
			insertion_index++;
		}
		jacobsthal_index++;
	}

	if (jabobsthal[jacobsthal_index] != list_pairs.size()) {
		pair_iterator = list_pairs.end();
		if (pair_iterator != list_pairs.begin())
			pair_iterator--;
		while (pair_iterator != last_jacobsthal) {
			slice_delimiter = std::find(results->begin(), results->end(), pair_iterator->first);
			binary_search_insertion(results, slice_delimiter, pair_iterator->first, insert_pos);
			pair_iterator--;
		}
	}
	if (additional_value != -1) {
		binary_search_insertion(results, results->end(), additional_value, insert_pos);
	}
}
template<typename M, typename I>
void printOutput(M results, I it) {
	std::cout << "After: ";
	for (it = results.begin(); it != results.end() ; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


#endif //CPP42_PMERGEME_HPP
