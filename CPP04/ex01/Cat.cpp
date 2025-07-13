//
// Created by voparkan on 3/7/25.
//

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
  std::cout << "Cat::Cat()" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)  {
	this->brain = new Brain();
	std::cout << "Cat::Cat(type)" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain();
	std::cout << "Cat::Cat(const Cat &other)" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		*this->brain = *other.brain;
	}
	std::cout << "Cat::Cat &operator=(const Cat &other)" << std::endl;
	return (*this);
}

Cat::~Cat() {
  delete this->brain;
  std::cout << "Cat::~Cat()" << std::endl;
}

std::string Cat::getType() const {
  return this->type;
}

void Cat::setType(std::string type) {
  this->type = type;
}

void Cat::makeSound() const {
  std::cout << "Cat::makeSound()" << std::endl;
}

Brain &Cat::getBrain(void) const
{
	return (*this->brain);
}
