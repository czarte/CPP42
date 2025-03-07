//
// Created by Vojtěch Parkán on 07/03/2025.
//

#include "Read.h"

Read::Read(std::string file_name) {
    this->file_name = file_name;
    this->fs.open(this->file_name, std::fstream::in);
}

Read::~Read() {};