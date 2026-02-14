//
// Created by Vojtěch Parkán on 14.02.2026.
//

#ifndef CPP42_SPAN_HPP
#define CPP42_SPAN_HPP
#include <vector>

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

//#define PUSH_MULTIPLE(T) \
//template<typename T, typename A, typename B, typename C, typename D, typename E, typename F> {\
//void push_many(std::vector<T>& v, const A& a, const B& b, const C& c, const D& d, const E& e, const F& f); }
#endif //CPP42_SPAN_HPP
