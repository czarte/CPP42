//
// Created by Vojtěch Parkán on 01.02.2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Read.h"
#include "Write.h"

int main(int argc, char** argv) {
	if (argc < 5) {
		std::cout << "Usage: ./replace <input.file> <output.file> find replace" << std::endl;
		return 0;
	}
    Read reader(argv[1]);
    Write writer(argv[2]);
	std::string word = argv[3];
	std::string replace = argv[4];

    reader.read_file(word, replace, writer);

	return (0);
}
