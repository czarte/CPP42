//
// Created by voparkan on 3/7/25.
//

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#define N_ANIMALS 20

int main()
{
	{
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i % 2)
				lotsOfAnimals[i] = new Dog();
			else
				lotsOfAnimals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		std::cout << lotsOfAnimals[0]->getType() << std::endl;
		std::cout << lotsOfAnimals[5]->getType() << std::endl;
		Brain *brain;
		brain = &lotsOfAnimals[0]->getBrain();
		brain->setIdea("I want sarshisitas!", 0);
		brain->setIdea("Let's play ball!!", 1);
		brain->setIdea("Feed me human!", 2);
		std::cout << lotsOfAnimals[0]->getBrain().getIdea(0) << std::endl;
		std::cout << lotsOfAnimals[0]->getBrain().getIdea(1) << std::endl;
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		dogA->getBrain().setIdea("I want sarshisitas!", 0);
		dogA->getBrain().setIdea("Let's play ball!!", 1);
		dogA->tell(0);
		dogA->tell(1);
		Dog *dogB = new Dog();
		Dog *dogC = new Dog(*dogA);

        dogC->tell(0);
		dogB->getBrain().setIdea("Feed me human!", 0);
		dogB->getBrain().setIdea("Feed me human!", 1);
		dogA->tell(0);
		dogA->tell(1);
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;
		dogA->getBrain().setIdea("I want sarshisitas!", 0);
        dogA->getBrain().setIdea("Let's play ball!!", 1);
		dogA->tell(0);
		dogA->tell(1);
        dogB->getBrain().setIdea("Feed me human!", 0);
        dogB->getBrain().setIdea("Feed me human!", 1);
		*dogA = *dogB;

        dogA->tell(0);
		dogA->tell(1);

		delete dogA;
		delete dogB;
	}
//	std::cout << "-------------------------------------\n";
//	{
//		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
//		Cat *catA = new Cat;
//		Cat *catB = new Cat(*catA);
//		std::cout << "-------------------------------------\n";
//		delete catA;
//		delete catB;
//	}


//	{
//		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
//		Cat *catA = new Cat;
//		Cat *catB = new Cat;
//
//		*catA = *catB;
//		delete catA;
//		delete catB;
//	}
	return (0);
}
