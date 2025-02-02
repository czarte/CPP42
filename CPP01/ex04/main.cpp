//
// Created by Vojtěch Parkán on 01.02.2025.
//

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
	if (argc < 5) {
		std::cout << "Usage: ./replace <input.file> <output.file> find replace" << std::endl;
		return 0;
	}
	std::string word = argv[3];
	std::string replace = argv[4];
	std::string buffer = "";
	std::fstream fs;
	fs.open (argv[1], std::fstream::in);
	int i = 0;
	char ch;
	while (fs.get(ch)) {
		if (ch == word[i]) {
			buffer.push_back(ch);
			i++;
			if (buffer.length() == word.length() && buffer == word) {
				std::cout << replace;
				buffer.erase();
				i = 0;
			} else if (buffer.length() == word.length() && buffer != word) {
				std::cout << buffer;
				buffer.erase();
			}
		} else {
			i = 0;
			if (!buffer.empty()) {
				std::cout << buffer;
			}
			buffer.erase();
			std::cout << ch;
		}
	}
	std::cout << std::endl;
	fs.close();
}
