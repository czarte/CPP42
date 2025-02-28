//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string name) {
	this->name = name;
    this->hitpoints = 100;
    this->energy = 50;
    this->damage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

//void ScavTrap::attack(const std::string &target) {
//	std::cout << "ScavTrap "
//		<< this->name << " attacks "
//		<< target << ", causing "
//		<< this->damage << " points of damage!"
//		<< std::endl;
//}

void ScavTrap::guardGate() {
	std::cout << "Guard!!!" << std::endl;
}