//
// Created by voparkan on 3/7/25.
//

#include "Cat.h"

Cat::Cat(): Animal() {
  this->setType("Cat");
  this->brain = new Brain();
  std::cout << "Cat::Cat()" << std::endl;
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