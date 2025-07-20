//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap(): ClapTrap("ScavTrap", 200, 100, 250) {
	this->hitpoints = 200;
    this->energy = 100;
    this->damage = 250;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 200, 100, 250) {
	std::cout << "ScavTrap Parametrized Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name, other.hitpoints, other.energy, other.damage) {
	this->hitpoints = other.hitpoints;
    this->energy = other.energy;
    this->damage = other.damage;
	std::cout << "ScavTrap::ScavTrap(const ScavTrap &other)" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap::ScavTrap &operator=(const ScavTrap &other)" << std::endl;
	if (this != &other) {
		this->name = other.name;
        this->hitpoints = other.hitpoints;
        this->energy = other.energy;
        this->damage = other.damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->damage << " points of damage!"
		<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "Guard!!!" << std::endl;
}