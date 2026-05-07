#include <vector>
#include "EasyFind.h"
#include <iostream>

int main(void ) {
	std::vector<int> a;
	for (int i = 0; i < 10000; ++i) {
        if (i % 2 == 0) {
        	a.push_back(i);
        }

	}

    try {
		if(*easyfind(a, 3))
        	std::cout << "Found in vector: " << *easyfind(a, 3) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Not found in vector: " << e.what() << std::endl;
    }
	try {
		if (*easyfind(a, 30))
			std::cout << "Found in vector: " << *easyfind(a, 30) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found in vector: " << e.what() << std::endl;
	}
	try {
		if (*easyfind(a, 2))
			std::cout << "Found in vector: " << *easyfind(a, 2) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found in vector: " << e.what() << std::endl;
	}

    for (size_t i = 0; i < a.size(); ++i) {
    	try {
    		if (*easyfind(a, i))
    			std::cout << "Found in vector: " << *easyfind(a, i) << std::endl;
    	} catch (const std::exception& e) {
    		std::cout << "Not found in vector: " << e.what() << std::endl;
    	}
    }
	return 0;
}
