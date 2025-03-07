//
// Created by voparkan on 3/7/25.
//

#include "Animal.h"

Animal::Animal() {
  this->type = "Animal";
  std::cout << "Animal::Animal()" << std::endl;
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