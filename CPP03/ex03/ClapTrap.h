//
// Created by Vojtěch Parkán on 23.02.2025.
//

#ifndef CPP42_CLAPTRAP_H
#define CPP42_CLAPTRAP_H

#include <iostream>

class ClapTrap {
  	protected:
		std::string name;
		unsigned int hitpoints;
		unsigned int energy;
		unsigned int damage;
	public:
        ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hitpoits, int energy, int damage);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
};


#endif //CPP42_CLAPTRAP_H
