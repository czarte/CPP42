//
// Created by Vojtěch Parkán on 31.01.2025.
//

#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void announce();
		static Zombie* newZombie( std::string name );
		static void randomChump( std::string name );
		explicit Zombie(const std::string& name);
};

#endif //CPP01_ZOMBIE_H
