#include <iostream>
#include <string>

char toUpperCase(char &c) {
	c = std::toupper(c);
	return c;
}

int main(int argc, char** argv) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::string word = argv[i];
		for(unsigned long e = 0; e < word.length(); e++) {
			toUpperCase(word[e]);
		}
		std::cout << word;
	}
	std::cout << std::endl;
	return 0;
}
