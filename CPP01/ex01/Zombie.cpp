//
// Created by Vojtěch Parkán on 31.01.2025.
//

#include "Zombie.h"

Zombie::Zombie() {}

void Zombie::nameZombie(const std::string& name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "Destructor for Zombie \"" << this->name << "\" was called" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

