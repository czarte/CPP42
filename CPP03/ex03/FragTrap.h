//
// Created by voparkan on 2/28/25.
//

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap {
    public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
	    ~FragTrap();
	    void highFivesGuys(void);
		void attack(const std::string& target);
};



#endif //FRAGTRAP_H
