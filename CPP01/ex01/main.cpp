//
// Created by Vojtěch Parkán on 31.01.2025.
//
#include "Zombie.h"

int main(void) {
	int horde_cnt = 42;
	Zombie* horde;

	std::cout << std::endl << "Welcom to my Zombie World" << std::endl;
	horde = Zombie::zombieHorde(horde_cnt, "horde");

	for (int i = 0; i < horde_cnt; ++i) {
		horde[i].announce();
	}

	delete [] horde;

	return (0);
}
