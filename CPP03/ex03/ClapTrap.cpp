//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap(): name("ClapTrap"), hitpoints(10), energy(10), damage(0) {
  std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitpoits, int energy, int damage): name(name), hitpoints(hitpoits), energy(energy), damage(damage) {
	std::cout << "ClapTrap Parametrized Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name) {
	std::cout << "ClapTrap Parametrized Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitpoints(10), energy(10), damage(0) {
	std::cout << "ClapTrap::ClapTrap(const ClapTrap &other)" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap::ClapTrap &operator=(const ClapTrap &other)" << std::endl;
	if (this != &other) {
		this->name = other.name;
        this->hitpoints = other.hitpoints;
        this->energy = other.energy;
        this->damage = other.damage;
	}
	return (*this);
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

void ClapTrap::takeDamage(unsigned int damage) {
	std::cout << "ClapTrap "
		<< this->name << " took damage "
		<< damage << std::endl;
}

void ClapTrap::beRepaired(unsigned int healing) {
	std::cout << "ClapTrap "
		<< this->name << " is repaired by "
		<< healing << std::endl;
}

std::string ClapTrap::getName(void) {
  return this->name;
}