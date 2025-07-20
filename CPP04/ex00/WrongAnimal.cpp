//
// Created by voparkan on 3/7/25.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal::WrongAnimal()" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
  this->type = type;
  std::cout << "WrongAnimal::WrongAnimal(type)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  *this = other;
  std::cout << "WrongAnimal::WrongAnimal(const WrongAnimal &other)" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  *this = other;
  std::cout << "WrongAnimal::WrongAnimal &operator=(const WrongAnimal &other)" << std::endl;
  return (*this);
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal::~WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal::makeSound" << std::endl;
}
