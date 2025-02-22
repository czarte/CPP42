//
// Created by Vojtěch Parkán on 16.02.2025.
//

#include "Fixed.h"

const int Fixed::fract_bits = 8;

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

	Fixed::Fixed(Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}


Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->value = src.getRawBits();
	return *this;
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
