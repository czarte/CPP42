#include "PhoneBook.h"
#include "Contact.h"

//
// Created by Vojtěch Parkán on 19.01.2025.
//
int	main() { //int argc, char** argv
	std::string inputs0[5] = {"1234", "czarte", "vojta", "parkan", "seru"};
	std::string inputs1[5] = {"2345", "toto", "tutu", "tata", "lolo"};
	std::string inputs2[5] = {"3467", "czarte", "vojta", "parkan", "seru"};
	std::string inputs3[5] = {"7890", "toto", "tutu", "tata", "lolo"};
	std::string inputs4[5] = {"0123", "czarte", "vojta", "parkan", "seru"};
	std::string inputs5[5] = {"101234", "toto", "tutu", "tata", "lolo"};
	std::string inputs6[5] = {"111234", "polo", "nono", "jojo", "seru"};
	std::string inputs7[5] = {"221234", "bobo", "koko", "roro", "fofo"};
	PhoneBook phonebook = PhoneBook();
	phonebook.add(0, inputs0);
	phonebook.add(1, inputs1);
	phonebook.add(2, inputs2);
	phonebook.add(3, inputs3);
	phonebook.add(4, inputs4);
	phonebook.add(5, inputs5);
	phonebook.add(6, inputs6);
	phonebook.add(7, inputs7);
	int exit_code = phonebook.loop();
	return (exit_code);
}
