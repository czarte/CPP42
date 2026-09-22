//
// Created by Vojtěch Parkán on 21.09.2025.
//

#ifndef CPP42_ARRAY_H
#define CPP42_ARRAY_H

#pragma once
#include <stdexcept>

template<typename T>
class Array {
    private:
        T* _data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        Array<T>& operator=(const Array<T>& other);
        ~Array();
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};

#include "Array.tpp"

#endif //CPP42_ARRAY_H
