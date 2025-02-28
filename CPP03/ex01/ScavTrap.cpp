//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string name): hitpoints(100), energy(50), damage(20) {
	this->name = name;
}

void ScavTrap::guardGate() {
	std::cout << "Guard!!!" << std::endl;
}