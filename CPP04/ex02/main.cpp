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
			if (i % 2) {
				lotsOfAnimals[i] = new Dog();
				Brain *brain;
				brain = &lotsOfAnimals[i]->getBrain();
				brain->setIdea("I want sarshisitas!", 0);
				brain->setIdea("Let's play ball!!", 1);
				brain->setIdea("Feed me human!", 2);
			} else {
				lotsOfAnimals[i] = new Cat();
				Brain *brain;
				brain = &lotsOfAnimals[i]->getBrain();
				brain->setIdea("Miauuuuu", 0);
				brain->setIdea("Miauuuuu Miauuuuu!!", 1);
				brain->setIdea("Miauuuuu Miauuuuu Miauuuuu!", 2);
            }
		}
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_ANIMALS; i++)
		{
			std::cout << lotsOfAnimals[i]->getType() << std::endl;
			std::cout << lotsOfAnimals[i]->getBrain().getIdea(0) << std::endl;
			std::cout << lotsOfAnimals[i]->getBrain().getIdea(1) << std::endl;
			std::cout << lotsOfAnimals[i]->getBrain().getIdea(2) << std::endl;
			std::cout << "-------------------------------------\n";
		}
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		std::cout << "---------------DogA---------------\n";
        Dog *dogA = new Dog;
		dogA->getBrain().setIdea("I want sarshisitas!", 0);
		dogA->getBrain().setIdea("Let's play ball!!", 1);
		dogA->tell(0);
		dogA->tell(1);
        std::cout << "---------------DogB---------------\n";
		Dog *dogB = new Dog();
        std::cout << "---------------DogC---------------\n";
		Dog *dogC = new Dog(*dogA);
        dogC->tell(0);
        std::cout << "---------------DogB---------------\n";
		dogB->getBrain().setIdea("Feed me human!", 0);
		dogB->getBrain().setIdea("Feed me human!", 1);
        dogB->tell(0);
		dogB->tell(1);
        std::cout << "---------------DogA---------------\n";
		dogA->tell(0);
		dogA->tell(1);
        dogA->tell(2);
        std::cout << "---------------Delete DogA+B------\n";
        delete dogC;
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

        dogA->tell(0);
		dogA->tell(1);

		delete dogA;
		delete dogB;
	}

	return (0);
}
