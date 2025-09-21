#include "iter.h"
#include <iostream>
#include <string>

template<typename T>
void increment(T &e) {
    e++;
}

template<typename T>
void print(T &e) {
    std::cout << e << std::endl;
}

int main() {
    std::string strings[] = {"apple", "banana", "cherry", "date"};
    int integers[] = {10, 20, 30, 40};

    std::cout << "Processing strings array:" << std::endl;
    iter(strings, 4, print<std::string>);

    std::cout << "Processing integers array:" << std::endl;
    iter(integers, 4, increment<int>);
    iter(integers, 4, print<int>);

    return 0;
}
