//
// Created by voparkan on 3/7/25.
//

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog::Dog()" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog::Dog(type)" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog::Dog(const Dog &other)" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog &other) : Animal(other) {
	std::cout << "Dog::Dog(Dog &other)" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Animal &other) : Animal(other) {
	std::cout << "Dog::Dog(const Dog &other)" << std::endl;
	this->brain = new Brain();
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog::Dog &operator=(const Dog &other)" << std::endl;
	Animal::operator=(other);
	if (this != &other) {
		*this->brain = *other.brain;
	}
	return (*this);
}

Dog &Dog::operator=(const Animal &other) {
	std::cout << "Dog::Dog &operator=(const Animal &other)" << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	delete this->brain;
	this->brain = new Brain();
	return (*this);
}

Dog::~Dog() {
  delete this->brain;
  std::cout << "Dog::~Dog()" << std::endl;
}

void Dog::setType(std::string type) {
  this->type = type;
}

std::string Dog::getType() const {
  return this->type;
}

void Dog::makeSound() const {
  std::cout << "Dog::makeSound()" << std::endl;
}
