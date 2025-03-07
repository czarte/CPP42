//
// Created by voparkan on 3/7/25.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Brain.h"

class Animal {
    protected:
      std::string type;
    public:
      Animal();
      virtual ~Animal();
      Animal(std::string type);
      virtual std::string getType() const = 0;
      virtual void makeSound() const = 0;
};



#endif //ANIMAL_H
