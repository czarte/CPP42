//
// Created by Vojtěch Parkán on 07/03/2025.
//

#include "Write.h"

Write::Write(const char* file_name) : file_name(file_name) {
    this->fs_out.open(this->file_name, std::fstream::out);
}

Write::~Write() {}

void Write::write_to_file(std::string to_write) {
     this->fs_out << to_write;
}

