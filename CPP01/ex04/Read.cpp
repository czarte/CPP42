//
// Created by Vojtěch Parkán on 07/03/2025.
//

#include "Read.h"

Read::Read(const char* file_name) : file_name(file_name) {
    this->fs.open(this->file_name, std::fstream::in);
    this->buffer = "";
}

Read::~Read() {}

void Read::read_file(std::string word, std::string replace, Write &write) {
    int i = 0;
    char ch;
    while (fs.get(ch)) {
        if (ch == word[i]) {
            buffer.push_back(ch);
            i++;
            if (buffer.length() == word.length() && buffer == word) {
                //std::cout << replace;
                write.write_to_file(replace);
                buffer.erase();
                i = 0;
            } else if (buffer.length() == word.length() && buffer != word) {
                //std::cout << buffer;
                write.write_to_file(buffer);
                buffer.erase();
            }
        } else {
            i = 0;
            if (!buffer.empty()) {
                write.write_to_file(buffer);

            }
            buffer.erase();
            std::string s = "";
            s.push_back(ch);
            write.write_to_file(s);
            //std::cout << ch;
        }
    }
}

std::string Read::get_buffer() {
  return this->buffer;
}

void Read::empty_buffer() {
  this->buffer.erase();
}