#include "Span.hpp"
#include <iostream>

template<typename T>
void push_many(std::vector<T>&) {}

template<typename T, typename A>
void push_many(std::vector<T> &v, const A& a) {
	v.push_back(a);
}

template<typename T, typename A, typename B>
void push_many(std::vector<T> &v, const A& a, const B& b) {
	v.push_back(a);
	v.push_back(b);
}

template<typename T, typename A, typename B, typename C, typename D, typename E, typename F>
void push_many(std::vector<T> &v, const A& a, const B& b, const C& c, const D& d, const E& e, const F& f) {
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);
}

#define PUSH_MULTIPLE(T, A, B) \
template<typename T, typename A, typename B> {\
void push_many(std::vector<T>& v, const A& a, const B& b) { \
	v.push_back(a);         \
	push_many(c, b);        \
}

int main(void) {
	Span s(2);
	push_many(s.get_vec(), 1, 2, 3, 4, 14, 17);
	std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
	std::cout << "Largest span: " << s.longestSpan() << std::endl;
	return 0;
}
