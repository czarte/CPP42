//
// Created by Vojtěch Parkán on 13.09.2025.
//

#include "Data.h"

// Default constructor
Data::Data() : value(0), name(""), price(0.0) {
}

// Parameterized constructor
Data::Data(int val, const std::string& n, double p) : value(val), name(n), price(p) {
}

// Copy constructor
Data::Data(const Data& other) : value(other.value), name(other.name), price(other.price) {
}

// Assignment operator
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        value = other.value;
        name = other.name;
        price = other.price;
    }
    return *this;
}

// Destructor
Data::~Data() {
}
