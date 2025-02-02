//
// Created by Vojtěch Parkán on 31.01.2025.
//

#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string name;
		Zombie* next_zombie;

	public:
		Zombie();
		~Zombie();
		void announce();
		static Zombie* newZombie( std::string name );
		static void randomChump( std::string name );
		void nameZombie(const std::string& name);
		static Zombie*  zombieHorde( int N, std::string name);
		static void addZombieNext(Zombie* zmb, Zombie* next);
		Zombie* newZombieMember(std::string name);
		Zombie* nextZombie();
};

#endif //CPP01_ZOMBIE_H
