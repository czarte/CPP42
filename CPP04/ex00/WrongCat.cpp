//
// Created by voparkan on 3/7/25.
//

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat::WrongCat()" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)  {
	std::cout << "WrongCat::WrongCat(type)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat::WrongCat(const WrongCat &other)" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  	*this = other;
	std::cout << "WrongCat::WrongCat &operator=(const WrongCat &other)" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat::~WrongCat()" << std::endl;
}

std::string WrongCat::getType() const {
	return this->type;
}

void WrongCat::setType(std::string type) {
	this->type = type;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat::makeSound()" << std::endl;
}

