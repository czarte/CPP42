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
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
		virtual Brain &getBrain(void) const = 0;
};



#endif //ANIMAL_H
