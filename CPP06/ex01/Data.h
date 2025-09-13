//
// Created by Vojtěch Parkán on 13.09.2025.
//

#ifndef CPP42_DATA_H
#define CPP42_DATA_H

#include <string>

struct Data {
    int value;
    std::string name;
    double price;

    // Default constructor
    Data();

    // Parameterized constructor
    Data(int val, const std::string& n, double p);

    // Copy constructor
    Data(const Data& other);

    // Assignment operator
    Data& operator=(const Data& other);

    // Destructor
    ~Data();
};

#endif //CPP42_DATA_H
