//
// Created by voparkan on 3/7/25.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
    protected:
      std::string type;
    public:
      Animal();
      virtual ~Animal();
      Animal(std::string type);
      virtual std::string getType() const;
      virtual void makeSound() const;
};



#endif //ANIMAL_H
