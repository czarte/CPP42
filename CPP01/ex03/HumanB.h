//
// Created by Vojtěch Parkán on 01.02.2025.
//

#ifndef CPP01_HUMANB_H
#define CPP01_HUMANB_H

#include <iostream>
#include "Weapon.h"

class HumanB {
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack();
};


#endif //CPP01_HUMANB_H
