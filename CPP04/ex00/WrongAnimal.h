//
// Created by voparkan on 3/7/25.
//

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include "Animal.h"

class WrongAnimal {
  	protected:
          std::string type;
    public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
	    virtual ~WrongAnimal();
	    void virtual makeSound() const;
};



#endif //WRONGANIMAL_H
