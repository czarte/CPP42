//
// Created by voparkan on 3/7/25.
//

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
    private:
      Brain* brain;
    public:
      Cat();
      ~Cat();
      std::string getType() const;
      void setType(std::string type);
      void makeSound() const;
};



#endif //CAT_H
