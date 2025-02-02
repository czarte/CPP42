//
// Created by Vojtěch Parkán on 01.02.2025.
//

#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	if (argc < 5) {
		std::cout << "Usage: ./replace <input.file> <output.file> find replace" << std::endl;
		return 0;
	}
	std::string word = argv[3];
	std::string replace = argv[4];
	std::string buffer;
	std::string filename = argv[1];
	std::fstream fs;
	fs.open (filename, std::fstream::in);
	char prev = '\0';
	while (fs >> buffer) {
		if (prev == '\n') {  // Check if the last character was a newline
			std::cout << std::endl;
		}
		int pos = buffer.find(word);
		if (pos != -1) {
			for (int n = 0;  n < pos; n++) {
				std::cout << buffer[n];
			}
			for (unsigned long m = 0; m < replace.length(); ++m) {
				std::cout << replace[m];
			}
			std::cout << " ";
			buffer.erase();
		} else {
			std::cout << buffer << " ";
		}
		prev = fs.peek();
	}
	std::cout << std::endl;
	fs.close();
}
