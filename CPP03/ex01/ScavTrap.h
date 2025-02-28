//
// Created by Vojtěch Parkán on 23.02.2025.
//

#ifndef CPP42_SCAVTRAP_H
#define CPP42_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
	public:
		~ScavTrap();
		ScavTrap(std::string name);
		void guardGate();
};


#endif //CPP42_SCAVTRAP_H
