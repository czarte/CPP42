//
// Created by Vojtěch Parkán on 26.04.2026.
//

#include "PmergeMe.hpp"

size_t PmergeMe::jacobsthalRecursion(int n) {
	if (n == 0)
		return (size_t) 0;
	if (n == 1)
		return (size_t) 1;
	else
		return size_t (PmergeMe::jacobsthalRecursion(n - 1) + 2 * PmergeMe::jacobsthalRecursion(n - 2));
}
std::vector<size_t> PmergeMe::jacobsthal() {
	std::vector<size_t> jv;
	for (int i = 0; i < JAC; ++i) {
		size_t n = PmergeMe::jacobsthalRecursion(i);
		if (n != 0) {
			jv.push_back(n);
		}

	}
	return jv;
}
bool PmergeMe::compareSize(std::pair<int, int> a, std::pair<int, int> b) {
	return (a.second < b.second);
}
void PmergeMe::printInput(char ** argv, int argc) {
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
}
void PmergeMe::printPairs(std::list<std::pair<int, int> > list_pairs) {
	std::cout << "list_pairs: ";
	for (std::list<std::pair<int, int> >::iterator it = list_pairs.begin(); it != list_pairs.end(); it++)
		std::cout << "|" << it->first << ", " << it->second << "| ";
	std::cout << std::endl;
}

void mergeSort(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end, size_t size) {
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size == 1)
		return;
	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::list<std::pair<int, int> >::iterator center = start;
	std::advance(center, firstHalf);

	mergeSort(start, center, firstHalf);
	mergeSort(center, end, secondHalf);
	std::inplace_merge(start, center, end, &PmergeMe::compareSize);
}

void mergeSort(std::deque<std::pair<int, int> >::iterator start, std::deque<std::pair<int, int> >::iterator end, size_t size) {
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size == 1)
		return;
	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::deque<std::pair<int, int> >::iterator center = start;
	std::advance(center, firstHalf);

	mergeSort(start, center, firstHalf);
	mergeSort(center, end, secondHalf);
	std::inplace_merge(start, center, end, &PmergeMe::compareSize);
}


//void createPairs(std::list<std::pair<int, int> > * list_pairs, char ** input, int * additional_value) {
//	int i = 1;
//	while (input[i]) {
//		int x = std::atoi(input[i]);
//		if (x < 0)
//			throw std::out_of_range("Only positive values");
//		if (input[i] && input[i + 1]) {
//			int y = std::atoi(input[i + 1]);
//			if (y < 0)
//				throw std::out_of_range("Only positive values");
//			std::pair<int, int> temp(x, y);
//			list_pairs->push_back(temp);
//			i += 2;
//		} else {
//			*additional_value = x;
//			i++;
//		}
//
//	}
//}
//void sortPairs(std::list<std::pair<int, int> > * list_pairs) {
//	for (std::list<std::pair<int, int> >::iterator it = list_pairs->begin(); it != list_pairs->end(); ++it) {
//		if (it->first > it->second)
//		{
//			int tmp = it->first;
//			it->first = it->second;
//			it->second = tmp;
//		}
//	}
//}
//void initResult(std::list<int> * results, std::list<std::pair<int, int> > list_pairs) {
//	for (std::list<std::pair<int, int> >::iterator it = list_pairs.begin(); it != list_pairs.end(); ++it) {
//		results->push_back(it->second);
//	}
//	if (!list_pairs.empty()) {
//		results->push_front(list_pairs.begin()->first);
//	}
//}
//void binarySearchInsertion(std::list<int> *results, std::list<int>::iterator end, int val) {
//	std::list<int>::iterator insert_pos = std::lower_bound(results->begin(), end, val);
//	results->insert(insert_pos, val);
///*
//	std::cout << "result current value: " << val << " : end iterator " << *end << " place to insert: " << *(insert_pos--) << std::endl;
//	for (std::list<int>::iterator it = results->begin(); it != results->end(); it++) {
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//*/
//}
//void insertIntoResult(std::list<std::pair<int, int> > list_pairs, std::list<int> * results, int additional_value) {
//	std::vector<size_t> jabobsthal = jacobsthal();
//	//size_t jabobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
//	int jacobsthal_index = 1;
//
//	std::list<int>::iterator slice_delimiter;
//	std::list<std::pair<int, int> >::iterator pair_iterator;
//	std::list<std::pair<int, int> >::iterator last_jacobsthal = list_pairs.begin();
//
//	while (jabobsthal[jacobsthal_index] <= list_pairs.size()) {
//		pair_iterator = list_pairs.begin();
//		std::advance(pair_iterator, jabobsthal[jacobsthal_index] - 1);
//		last_jacobsthal = pair_iterator;
//
//		int insertion_index = 0;
//		while (jabobsthal[jacobsthal_index] - insertion_index > jabobsthal[jacobsthal_index - 1]) {
//			slice_delimiter = std::find(results->begin(), results->end(), pair_iterator->second);
//			binarySearchInsertion(results, slice_delimiter, pair_iterator->first);
//			pair_iterator--;
//			insertion_index++;
//		}
//		jacobsthal_index++;
//	}
//
//	if (jabobsthal[jacobsthal_index] != list_pairs.size()) {
//		pair_iterator = list_pairs.end();
//		if (pair_iterator != list_pairs.begin())
//			pair_iterator--;
//		while (pair_iterator != last_jacobsthal) {
//			slice_delimiter = std::find(results->begin(), results->end(), pair_iterator->first);
//			binarySearchInsertion(results, slice_delimiter, pair_iterator->first);
//			pair_iterator--;
//		}
//	}
//	if (additional_value != -1) {
//		binarySearchInsertion(results, results->end(), additional_value);
//	}
//
//}
//void printOutput(std::list<int> results) {
//	std::cout << "After: ";
//	for (std::list<int>::iterator it = results.begin(); it != results.end() ; it++) {
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//}
