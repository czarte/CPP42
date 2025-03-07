//
// Created by voparkan on 3/7/25.
//

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include "Animal.h"

class WrongAnimal :public Animal {
    public:
      WrongAnimal();
      ~WrongAnimal();
      void virtual makeSound() const;
};



#endif //WRONGANIMAL_H
