//
// Created by Vojtěch Parkán on 01.02.2025.
//

#include "HumanB.h"

HumanB::~HumanB() {}

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon1) {
	this->weapon = &weapon1;
}

void HumanB::attack() {
	if (this->weapon) {
		std::cout << this->name << " attacks with their "
				  << this->weapon->getType() << std::endl;
	} else {
		std::cout << this->name << " is unarmed" << std::endl;
	}
}
