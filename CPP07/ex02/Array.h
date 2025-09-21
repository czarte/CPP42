//
// Created by Vojtěch Parkán on 21.09.2025.
//

#ifndef CPP42_ARRAY_H
#define CPP42_ARRAY_H

#include <stdexcept>

template<typename T>
class Array {
public:
    // Default constructor - creates empty array
    Array();

    // Parameterized constructor - creates array of n elements
    Array(unsigned int n);

    // Copy constructor
    Array(const Array<T>& other);

    // Copy assignment operator
    Array<T>& operator=(const Array<T>& other);

    // Destructor
    ~Array();

    // Subscript operator with bounds checking
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // Size getter
    unsigned int size() const;

private:
    T* _data;
    unsigned int _size;
};

#include "Array.tpp"

#endif //CPP42_ARRAY_H
