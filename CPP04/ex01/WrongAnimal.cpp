//
// Created by voparkan on 3/7/25.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
  this->type = "WrongAnimal";
  std::cout << "WrongAnimal::WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal::~WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal::makeSound" << std::endl;
}