//
// Created by Vojtěch Parkán on 07/03/2025.
//

#ifndef CPP42_READ_H
#define CPP42_READ_H


class Read {
    private:
        std::string file_name;
        std::string buffer;
        std::fstream fs;
    public:
        Read(std::string file_name);
        ~Read();
        std::fstream open_file();
        void close_file();
};


#endif //CPP42_READ_H
