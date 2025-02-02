//
// Created by Vojtěch Parkán on 01.02.2025.
//

#ifndef CPP01_WEAPON_H
#define CPP01_WEAPON_H

#include <iostream>

class Weapon {
	private:
		std::string type;

	public:
		Weapon();
		~Weapon();
		explicit Weapon(std::string name);
		const std::string& getType();
		void setType(std::string name);
};


#endif //CPP01_WEAPON_H
