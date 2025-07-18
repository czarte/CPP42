//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ClapTrap.h"

int main(void) {
	ClapTrap a("dement");
	a.attack("hovno");
    a.takeDamage(10);
    a.beRepaired(5);
	return (0);
}
