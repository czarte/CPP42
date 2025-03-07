//
// Created by voparkan on 3/7/25.
//

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;
    return 0;
}