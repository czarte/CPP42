//
// Created by Vojtěch Parkán on 31.01.2025.
//

#include "Zombie.h"
#include <sstream>


Zombie*  Zombie::zombieHorde( int N, std::string name) {
	Zombie* zombies = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		std::ostringstream oss;
        oss << "zombie " << i + 1 << ' ' << name;
        std::string thisname = oss.str();
		zombies[i].nameZombie(thisname);
	}

	return zombies;
}

