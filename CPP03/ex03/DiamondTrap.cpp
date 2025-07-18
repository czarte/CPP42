//
// Created by voparkan on 7/18/25.
//

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultClapTrap") {
  this->_name = "DiamondTrap";
  this->_hitpoints = FragTrap::hitpoints;
  this->_energy = ScavTrap::energy;
  this->_damage = FragTrap::damage;
  std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap") {
  this->_name = name;
  this->_hitpoints = FragTrap::hitpoints;
  this->_energy = ScavTrap::energy;
  this->_damage = FragTrap::damage;
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
    this->_name = other._name;
    this->_hitpoints = other._hitpoints;
    this->_energy = other._energy;
    this->_damage = other._damage;
  }
  return (*this);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "-----------WHOAMI-------------" << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
  std::cout << "DiamondTrap: " << this->_name << std::endl;
  std::cout << "energy: " << this->_energy << std::endl;
  std::cout << "hitpoints: " << this->_hitpoints << std::endl;
  std::cout << "damage: " << this->_damage << std::endl;
  std::cout << "-------------------------------" << std::endl;
}

std::string DiamondTrap::getName(void) {
  return (this->_name);
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destruction" << std::endl;
}