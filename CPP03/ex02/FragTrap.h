//
// Created by voparkan on 2/28/25.
//

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
    public:
      FragTrap(std::string name);
      ~FragTrap();
      void highFivesGuys(void);
};



#endif //FRAGTRAP_H
