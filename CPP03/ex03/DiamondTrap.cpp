//
// Created by voparkan on 7/18/25.
//

#include "DiamondTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

DiamondTrap::DiamondTrap() {
  this->name = "DiamondTrap";
  this->hitpoints = FragTrap::hitpoints;
  this->energy = ScavTrap::energy;
  this->damage = FragTrap::damage;
  std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
  this->name = name;
  this->hitpoints = FragTrap::hitpoints;
  this->energy = ScavTrap::energy;
  this->damage = FragTrap::damage;
  std::cout << "ScavTrap::energy " << ScavTrap::energy << std::endl;
  std::cout << "DiamondTrap Parametrized Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  *this = other;
  std::cout << "DiamondTrap::DiamondTrap(const DiamondTrap &other)" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap::DiamondTrap &operator=(const DiamondTrap &other)" << std::endl;
  if (this != &other) {
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energy = other.energy;
    this->damage = other.damage;
  }
  return (*this);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "-----------WHOAMI-------------" << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
  std::cout << "DiamondTrap: " << this->name << std::endl;
  std::cout << "energy: " << this->energy << std::endl;
  std::cout << "hitpoints: " << this->hitpoints << std::endl;
  std::cout << "damage: " << this->damage << std::endl;
  std::cout << "-------------------------------" << std::endl;
}

std::string DiamondTrap::getName(void) {
  return (this->name);
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destruction" << std::endl;
}