//
// Created by voparkan on 3/7/25.
//

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

//TODO assignment operator Cat &operator=(const Cat &src);
// and copy constructor Cat(Cat const &copy);

class Cat : public Animal {
    private:
      	Brain* brain;
    public:
      	Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		std::string getType() const;
		void setType(std::string type);
		void makeSound() const;
};



#endif //CAT_H


