//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ScavTrap.h"
#include "FragTrap.h"

int main(void) {
	ClapTrap a;
	ScavTrap b("scavanger");
	FragTrap c("fragger");

	a.attack("bubu");
    b.attack("kuku");
	c.attack("susu");
    b.guardGate();
	c.highFivesGuys();
	return (0);
}
