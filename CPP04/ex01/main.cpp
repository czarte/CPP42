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
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	const Animal* b(i);
	Dog* d = new Dog();
	Dog* f = d;
	Dog* g(f);
	const Animal* l(j);
	const Animal* c = j;
	std::cout << "---------------" << std::endl;
	g->makeSound();
	std::cout << b->getType() << std::endl;
	c->makeSound();
	l->makeSound();
	delete d;
	delete i;
    delete j;//should not create a leak

    return 0;
}
