//
// Created by Vojtěch Parkán on 01.02.2025.
//

#include "Weapon.h"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(std::string name) {
	this->type = name;
}

const std::string &Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string name) {
	this->type = name;
}
