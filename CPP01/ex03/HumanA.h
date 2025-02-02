//
// Created by Vojtěch Parkán on 01.02.2025.
//

#ifndef CPP01_HUMANA_H
#define CPP01_HUMANA_H

#include <iostream>
#include "Weapon.h"

class HumanA {
	private:
		std::string name;
		Weapon& weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
};


#endif //CPP01_HUMANA_H
