//
// Created by voparkan on 3/7/25.
//

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
    public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();
		std::string getType() const;
		void setType(std::string type);
		void makeSound() const;
};



#endif //WRONGCAT_H
