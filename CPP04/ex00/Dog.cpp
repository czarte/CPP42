//
// Created by voparkan on 3/7/25.
//

#include "Dog.h"

Dog::Dog(): Animal() {
  this->setType("Dog");
  std::cout << "Dog::Dog()" << std::endl;
}
Dog::~Dog() {
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