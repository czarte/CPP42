//
// Created by voparkan on 3/7/25.
//

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
    std::cout << "---------Animal------------" << std::endl;
    const Animal* meta = new Animal();
    std::cout << "---------Cat&Dog-----------" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "---------WAnimal&WCat------" << std::endl;
    const WrongAnimal* w = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << "---------Dog---------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    std::cout << "---------Cat---------------" << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << "---------Animal------------" << std::endl;
    meta->makeSound();
    std::cout << "---------WrongAnimal-------" << std::endl;
    w->makeSound();
    std::cout << "---------WrongCat----------" << std::endl;
    wc->makeSound();
    std::cout << "---------Delete animals----" << std::endl;
    delete w;
    delete wc;
    delete j;
    delete i;
    delete meta;
    return 0;
}
