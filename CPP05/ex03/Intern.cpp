//
// Created by Vojtěch Parkán on 07.09.2025.
//

#include "Intern.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

Intern::Intern() {}

Intern::~Intern() {}

AForm * Intern::makeForm(std::string form, std::string target) {
	AForm *(Intern::*create[3])() = {
			&Intern::createShrubberyForm,
			&Intern::createRobotomyForm,
			&Intern::createPresidentialForm
	};
	std::string action[3] = { "shrubbery", "robotomy", "pardon" };
	int i = 0;
	while (form != action[i])
		i++;
	if (i < 3)
		return (this->*create[i])();
	else
		std::cout << "nothign to log"; //TODO throw an exeption
	return NULL;
}
