//
// Created by voparkan on 10/4/25.
//

#ifndef EASYFIND_H
#define EASYFIND_H

#pragma once
#include <stdexcept>

template <typename T>
typename T::iterator eastfind(T &arr, int n) {
	typename T::iterator i;
	    for (i = arr.begin(); i != arr.end(); i++) {
			if (i == arr.end())
				throw std::out_of_range("Array out of range");
			if (*i == n)
				return i;
	    }
}

#endif //EASYFIND_H
