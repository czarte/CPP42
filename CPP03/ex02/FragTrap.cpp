//
// Created by voparkan on 2/28/25.
//

#include "FragTrap.h"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitpoints = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap cosntructor called!!!" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "\"High Fives Guys\"" << std::endl;
}