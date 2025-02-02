//
// Created by Vojtěch Parkán on 31.01.2025.
//
#include "Zombie.h"

int main(void) {
	std::cout << std::endl << "Welcom to my Zombie World" << std::endl;
	Zombie boo = Zombie("Boo");
	Zombie* coo = Zombie::newZombie("Coo");
	coo->announce();
	boo.announce();
	Zombie::randomChump("Loo");
	delete coo;
}
