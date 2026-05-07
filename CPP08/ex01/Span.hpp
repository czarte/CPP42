//
// Created by Vojtěch Parkán on 14.02.2026.
//

#ifndef CPP42_SPAN_HPP
#define CPP42_SPAN_HPP
#include <vector>
#include <cstddef>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <limits>

class Span {
	private:
		std::vector<int> 	_vec;
		size_t 				_size;
	public:
		Span(size_t size);
		~Span();
		Span(const Span &src);
		Span& operator=(const Span &other);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		std::vector<int> & get_vec();
};

#endif //CPP42_SPAN_HPP
