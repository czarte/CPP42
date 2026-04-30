#include "PmergeMe.hpp"

int main(int argc, char ** argv) {
	if (argc < 2) {
		std::cerr << "No numbers provided\n";
		return (1);
	}
    bool pass = true;
	//std::list solution
	{
		std::list<std::pair<int, int> > list_pairs;
		std::list<int> results;
		std::list<int>::iterator it;
		std::list<std::pair<int, int> >::iterator pair_it;
		std::list<std::pair<int, int> >::iterator last_jacobsthal;
		std::list<int>::iterator slice_delimiter;
		int additional_value = -1;
		PmergeMe::printInput(argv, argc);

		clock_t start = clock();

		try {
			createPairs(&list_pairs, argv, &additional_value);
			sortPairs(&list_pairs, pair_it);
			//PmergeMe::printPairs(list_pairs);
			mergeSort(list_pairs.begin(), list_pairs.end(), 0);
			initResult(&results, list_pairs, pair_it);
			insertIntoResult(list_pairs, &results, additional_value, pair_it, last_jacobsthal, slice_delimiter, it);
			printOutput(results, it);
			clock_t end = clock();
			std::cout << "Time to process a range of " << results.size()
					  << " elements with std::list "
					  << static_cast<double>(end - start) / 1000 << " ms"
					  << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			pass = false;
		}
	}
	//std::deque solution
    if (pass)
	{
		std::deque<std::pair<int, int> > list_pairs;
		std::deque<int> results;
		std::deque<int>::iterator it;
		std::deque<std::pair<int, int> >::iterator pair_it;
		std::deque<std::pair<int, int> >::iterator last_jacobsthal;
		std::deque<int>::iterator slice_delimiter;
		int additional_value = -1;
		//PmergeMe::printInput(argv, argc);

		clock_t start = clock();

		try {
			createPairs(&list_pairs, argv, &additional_value);
			sortPairs(&list_pairs, pair_it);
			//printPairs(list_pairs);
			mergeSort(list_pairs.begin(), list_pairs.end(), 0);
			initResult(&results, list_pairs, pair_it);
			//std::cout << std::endl << "DEBUG: Result after initialization" << std::endl;
			//printOutput(results, it);
			insertIntoResult(list_pairs, &results, additional_value, pair_it, last_jacobsthal, slice_delimiter, it);
			//printOutput(results, it);
			clock_t end = clock();
			std::cout << "Time to process a range of " << results.size()
					  << " elements with std::deque "
					  << static_cast<double>(end - start) / 1000 << " ms"
					  << std::endl << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
