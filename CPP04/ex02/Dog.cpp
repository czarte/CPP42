//
// Created by voparkan on 3/7/25.
//

#include "Dog.h"

Dog::Dog(): Animal() {
  this->setType("Dog");
  this->brain = new Brain();
  std::cout << "Dog::Dog()" << std::endl;
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