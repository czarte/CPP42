//
// Created by Vojtěch Parkán on 31.01.2025.
//

#include "Zombie.h"

Zombie*  Zombie::zombieHorde( int N, std::string name) {
	Zombie* zombies = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		zombies[i].nameZombie(name);
	}

	return zombies;
}

