#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		PmergeMe::printInput(argc, argv);
		PmergeMe::runList(argc, argv);
		PmergeMe::runDeque(argc, argv);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
