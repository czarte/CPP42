//
// Created by Vojtěch Parkán on 31.01.2025.
//
#include <iostream>

int main(void) {
	std::string brain =  "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << std::hex << &brain << std::endl;
	std::cout << std::hex << stringPTR << std::endl;
	std::cout << std::hex << &stringREF << std::endl;

	std::cout << std::hex << brain << std::endl;
	std::cout << std::hex << *stringPTR << std::endl;
	std::cout << std::hex << stringREF << std::endl;
	return (0);
}
