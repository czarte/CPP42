//
// Created by Vojtěch Parkán on 01.02.2025.
//

#include "HumanA.h"

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon) {
	this->name = name;
	this->weapon = weapon;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their "
				<< this->weapon.getType() << std::endl;
}
