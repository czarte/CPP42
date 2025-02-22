//
// Created by Vojtěch Parkán on 16.02.2025.
//

#include "Fixed.h"

const int Fixed::fract_bits = 8;

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	this->value = value << fract_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
	this->value = roundf(value * (1 << fract_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
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

float operator*(Fixed const &src1, Fixed const &src2) {
	return src1.getRawBits() * src2.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Fixed destructor called" << std::endl;
}

int Fixed::getRawBits()const {
	std::cout << "getRawBits was called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits was called" << std::endl;
	this->value = raw;
}

int Fixed::toInt()const {
	return (this->value >> fract_bits);
}

float Fixed::toFloat() const {
	return (float)this->value / (float)(1 << fract_bits);
}
