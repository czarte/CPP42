//
// Created by Vojtěch Parkán on 07.09.2025.
//

#ifndef CPP42_INTERN_H
#define CPP42_INTERN_H

#include <iostream>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
	public:
		Intern();
		Intern(const Intern & other);
		~Intern();
		const Intern & operator=(const Intern & other);
		AForm * makeForm(std::string form, std::string target);
		AForm * createShrubberyForm();
		AForm * createRobotomyForm();
		AForm * createPresidentialForm();
};


#endif //CPP42_INTERN_H
