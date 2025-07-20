//
// Created by voparkan on 3/7/25.
//

#include "Animal.h"

Animal::Animal() : type("Animal") { //, brain(new Brain()
  std::cout << "Animal::Animal()" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
  std::cout << "Animal::Animal(type)" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
  std::cout << "Animal::Animal(const Animal &other)" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal::Animal &operator=(const Animal &other)" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return (*this);
}

Animal::~Animal() {
  std::cout << "Animal::~Animal()" << std::endl;
}

void Animal::makeSound() const {
  std::cout << "Animal::makeSound()" << std::endl;
}

std::string Animal::getType() const {
  return this->type;
}
