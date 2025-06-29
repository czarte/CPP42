//
// Created by voparkan on 3/7/25.
//

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
    private:
        Brain* brain;
    public:
      Dog();
      ~Dog();
      std::string getType() const;
      void setType(std::string type);
      void makeSound() const;
};



#endif //DOG_H
