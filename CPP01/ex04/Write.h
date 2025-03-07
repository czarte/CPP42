//
// Created by Vojtěch Parkán on 07/03/2025.
//

#ifndef CPP42_WRITE_H
#define CPP42_WRITE_H

#include <iostream>
#include <fstream>
#include <string>

class Write {
    private:
        const char* file_name;
        std::fstream fs_out;
    public:
        Write(const char* file_name);
        ~Write();
        void write_to_file(std::string to_write);
};


#endif //CPP42_WRITE_H
