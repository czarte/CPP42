//
// Created by Vojtěch Parkán on 20.09.2025.
//

#ifndef CPP42_ITER_H
#define CPP42_ITER_H

#include <iostream>

#pragma once

//template<typename T>
//void iter(const T* array, size_t length, void (*func)(T &)) {
//    for (size_t i = 0; i < length; ++i) {
//        func(array[i]);
//    }
//}

template<typename T, typename F>
void iter(T* array, size_t length, F func) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

#endif //CPP42_ITER_H
