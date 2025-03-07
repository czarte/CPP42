//
// Created by Vojtěch Parkán on 07/03/2025.
//

#ifndef CPP42_READ_H
#define CPP42_READ_H

#include <iostream>
#include <fstream>
#include <string>
#include "Write.h"

class Read {
    private:
        const char* file_name;
        std::string buffer;
        std::fstream fs;
    public:
        Read(const char* file_name);
        ~Read();
        std::fstream open_file();
        void close_file();
        std::string get_buffer();
        void empty_buffer();
        void read_file(std::string find, std::string replace, Write &write);

};


#endif //CPP42_READ_H
