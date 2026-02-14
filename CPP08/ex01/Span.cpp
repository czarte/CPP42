//
// Created by Vojtěch Parkán on 14.02.2026.
//
#include "Span.hpp"

Span::Span(size_t size) : _size(size) {}
Span::~Span() {}
Span::Span(const Span &src) {
	*this = src;
}
Span& Span::operator=(const Span &other) {
	if (this != &other) {
		this->_vec = other._vec;
		this->_size = other._size;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (this->_vec.size() > this->_size)
		throw std::out_of_range("Span is already full");
	_vec.push_back(n);
}
int Span::shortestSpan() {
	if (this->_vec.empty() || this->_vec.size() == 1)
		throw std::out_of_range("Span has to have minimum 2 members");

	std::vector<int> temp = this->_vec;
	std::sort(temp.begin(), temp.end());
	int min = std::numeric_limits<int>::max();
	for (size_t size = 0; size < this->_size; ++size) {
		int span = temp[size + 1] - temp[size];
		if (span < min)
			min = span;
	}
	return min;
}
int Span::longestSpan() {
	if (this->_vec.empty() || this->_vec.size() == 1)
		throw std::out_of_range("Span has to have minimum 2 members");

	std::vector<int>::const_iterator max = std::max_element(this->_vec.begin(),
															this->_vec.end());
	std::vector<int>::const_iterator min = std::min_element(this->_vec.begin(),
															this->_vec.end());
	return *max - *min;
}
std::vector<int> & Span::get_vec() {
	return _vec;
}
