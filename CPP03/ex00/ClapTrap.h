//
// Created by Vojtěch Parkán on 23.02.2025.
//

#ifndef CPP42_CLAPTRAP_H
#define CPP42_CLAPTRAP_H

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		unsigned int hitpoints;
		unsigned int energy;
		unsigned int damage;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif //CPP42_CLAPTRAP_H
