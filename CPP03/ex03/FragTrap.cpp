//
// Created by voparkan on 2/28/25.
//

#include "FragTrap.h"

FragTrap::FragTrap(): ClapTrap("FragTrap") {
	hitpoints = 8000;
	energy = 300;
	damage = 800;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	hitpoints = 8000;
	energy = 300;
	damage = 800;
	std::cout << "FragTrap Parametrized Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name) {
	this->hitpoints = other.hitpoints;
	this->energy = other.energy;
	this->damage = other.damage;
	std::cout << "FragTrap::FragTrap(const FragTrap &other)" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap::FragTrap &operator=(const FragTrap &other)" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->damage << " points of damage!"
		<< std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "\"High Fives Guys\"" << std::endl;
}