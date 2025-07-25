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
		Dog(std::string type);
		Dog(Dog &other);
		Dog &operator=(Dog &other);
		Dog &operator=(const Animal &other);
		~Dog();
		std::string getType() const;
	    Brain &getBrain(void) const;
		void setType(std::string type);
		void makeSound() const;
        void tell(int i) const;
};



#endif //DOG_H
