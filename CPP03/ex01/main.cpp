//
// Created by Vojtěch Parkán on 23.02.2025.
//

#include "ScavTrap.h"

int main(void) {
	ClapTrap a;
	std::cout << "---------------" << std::endl;
	ScavTrap b("scavanger");
	std::cout << "---------------" << std::endl;
	ScavTrap x = ScavTrap();
	std::cout << "---------------" << std::endl;
	ScavTrap c = b;
	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;
	x.attack("scavanger");
    c.guardGate();
	a.attack("bubu");
    b.attack("kuku");
    b.guardGate();
	return (0);
}
