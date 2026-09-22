//
// Created by Vojtěch Parkán on 13.09.2025.
//

#ifndef CPP42_SERIALIZER_H
#define CPP42_SERIALIZER_H

#include <stdint.h>
#include "Data.h"

class Serializer {
private:
    // Private constructor to prevent instantiation
    Serializer();

    // Private copy constructor to prevent instantiation
    Serializer(const Serializer& other);

    // Private assignment operator to prevent instantiation
    Serializer& operator=(const Serializer& other);

    // Private destructor to prevent instantiation
    ~Serializer();

public:
    // Static method to serialize Data pointer to uintptr_t
    static uintptr_t serialize(Data* ptr);

    // Static method to deserialize uintptr_t to Data pointer
    static Data* deserialize(uintptr_t raw);
};

#endif //CPP42_SERIALIZER_H
