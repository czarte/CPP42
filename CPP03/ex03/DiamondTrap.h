//
// Created by voparkan on 7/18/25.
//

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap {
	private:
    	std::string name;
    public:
	    DiamondTrap(void);
	    DiamondTrap(std::string name);
	    DiamondTrap(const DiamondTrap& src);
	    ~DiamondTrap(void);
	    DiamondTrap& operator=(const DiamondTrap& other);
	    void whoAmI(void);
		std::string getName(void);
	    void attack(const std::string& target);
};



#endif //DIAMONDTRAP_H
