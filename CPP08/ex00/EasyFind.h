//
// Created by voparkan on 10/4/25.
//

#ifndef EASYFIND_H
#define EASYFIND_H

#pragma once
#include <exception>
#include <algorithm>

class NotFoundExeption : public std::exception
{
public:
	virtual const char* what() const throw() {
		return ("Out of bounds");
	}
};

template <typename T>
typename T::iterator easyfind(T &arr, int n) {

	typename T::iterator i;

	i = std::find(arr.begin(), arr.end(), n);
	if (i == arr.end())
		throw NotFoundExeption();
	return i;
}

#endif //EASYFIND_H
