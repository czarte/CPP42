//
// Created by voparkan on 3/7/25.
//

#include "Brain.h"

Brain::Brain() {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = "";
  }
  std::cout << "Brain Constructor" << std::endl;
}

Brain::~Brain() {
  std::cout << "Brain Destructor" << std::endl;
}