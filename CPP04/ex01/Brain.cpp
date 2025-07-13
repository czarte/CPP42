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

void Brain::setIdea(const std::string &idea, const int &index) {
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(const int &index) {
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	else
		return ("Out of the bound exception");
}
