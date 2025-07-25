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
  	Animal *aniA = new Animal();
    aniA->makeSound();
    delete aniA;
	{
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i % 2) {
				lotsOfAnimals[i] = new Dog();

			} else {
				lotsOfAnimals[i] = new Cat();
            }
		}
		std::cout << "-------------------------------------\n";
        for (int i = 0; i < N_ANIMALS; i++)
		{
			const Dog* dog = dynamic_cast<const Dog*>(lotsOfAnimals[i]);
            if (dog) {
            	Brain *b = &dog->getBrain();
            	b->setIdea("I want sarshisitas!", 0);
				b->setIdea("Let's play ball!!", 1);
				b->setIdea("Feed me human!", 2);
        	}
		}

        for (int i = 0; i < N_ANIMALS; i++)
		{
			const Dog* dog = dynamic_cast<const Dog*>(lotsOfAnimals[i]);
            if (dog) {
            	Brain *b = &dog->getBrain();
            	std::cout << b->getIdea(0) << std::endl;
				std::cout << b->getIdea(1) << std::endl;
                std::cout << b->getIdea(2) << std::endl;
        	}
		}
		std::cout << lotsOfAnimals[0]->getType() << std::endl;
		std::cout << lotsOfAnimals[5]->getType() << std::endl;

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
