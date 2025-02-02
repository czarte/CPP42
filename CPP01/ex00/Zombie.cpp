//
// Created by Vojtěch Parkán on 31.01.2025.
//

#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "Destructor for Zombie \"" << this->name << "\" was called" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name) {
	Zombie *zmb = new Zombie(name);
	return (Zombie *) zmb;
}

void Zombie::randomChump(std::string name) {
	Zombie chump = Zombie(name);
	chump.announce();
}
