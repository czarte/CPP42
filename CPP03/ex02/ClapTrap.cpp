//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap(std::string name) {
  this->name = name;
}

ClapTrap::ClapTrap(): hitpoints(10), energy(10), damage(0) {
  	this->name = "ClapTrap";
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->damage << " points of damage!"
		<< std::endl;
}
