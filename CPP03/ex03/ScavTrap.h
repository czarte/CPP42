//
// Created by Vojtěch Parkán on 23.02.2025.
//

#ifndef CPP42_SCAVTRAP_H
#define CPP42_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};


#endif //CPP42_SCAVTRAP_H
