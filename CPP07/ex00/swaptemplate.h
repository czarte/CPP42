//
// Created by Vojtěch Parkán on 20.09.2025.
//

#ifndef CPP42_SWAPTEMPLATE_H
#define CPP42_SWAPTEMPLATE_H

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

template<typename T>
T max(T const& a, T const& b) {
    return (a > b) ? a : b;
}

#endif //CPP42_SWAPTEMPLATE_H
