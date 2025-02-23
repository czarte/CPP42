//
// Created by Vojtěch Parkán on 16.02.2025.
//

#include "Fixed.h"

const int Fixed::fract_bits = 8;

Fixed::Fixed(): value(0) {}

Fixed::Fixed(const int value) {
	this->value = value << fract_bits;
}

Fixed::Fixed(const float value) {
	this->value = roundf(value * (1 << fract_bits));
}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src)
		this->value = src.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& o, Fixed const &src) {
	o << src.toFloat();
	return o;
}

bool operator<(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() < src2.getRawBits();
}

bool operator>(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() > src2.getRawBits();
}

bool operator>=(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() >= src2.getRawBits();
}

bool operator<=(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() <= src2.getRawBits();
}

bool operator==(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() == src2.getRawBits();
}

bool operator!=(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() != src2.getRawBits();
}

float operator+(Fixed const &src1, Fixed const &src2) {
	//std::cout << "+ overload was called" << std::endl;
	return src1.toFloat() + src2.toFloat();
}

float operator-(Fixed const &src1, Fixed const &src2) {
	return src1.toFloat() - src2.toFloat();
}

float operator*(Fixed const &src1, Fixed const &src2) {
	return src1.toFloat() * src2.toFloat();
}

float operator/(Fixed const &src1, Fixed const &src2) {
	return src1.toFloat() / src2.toFloat();
}

Fixed& Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp;
	tmp = *this;
	operator++();
	return tmp;
}

Fixed::~Fixed() {}

int Fixed::getRawBits()const {
	return (this->value);
}

void Fixed::setRawBits(const int raw) {
	this->value = raw;
}

int Fixed::toInt()const {
	return (this->value >> fract_bits);
}

float Fixed::toFloat() const {
	return (float)this->value / (float)(1 << fract_bits);
}

Fixed const& Fixed::max(Fixed const &src1, Fixed const &src2) {
	if (src1.toFloat() > src2.toFloat()) {
		return src1;
	} else {
		return src2;
	}
}

Fixed& Fixed::max(Fixed &src1, Fixed &src2) {
	if (src1.toFloat() > src2.toFloat()) {
		return src1;
	} else {
		return src2;
	}
}
