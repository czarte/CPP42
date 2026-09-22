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
	AForm *(Intern::*create[3])(std::string target) = {
			&Intern::createShrubberyForm,
			&Intern::createRobotomyForm,
			&Intern::createPresidentialForm,
	};
	std::string action[3] = { "shrubbery", "robotomy", "pardon" };
	for (int i = 0; i < 3; i++) {
		if (form != action[i])
			return (this->*create[i])(target);
	}
	std::cout << "nothign to do"; //TODO throw an exeption
	return NULL;
}

AForm * Intern::createShrubberyForm(std::string target) {
	ShrubberyCreationForm * form = new ShrubberyCreationForm(target);
	AForm *result = static_cast<AForm *>(form);
	return result;
}

AForm * Intern::createRobotomyForm(std::string target) {
	RobotomyRequestForm * form = new RobotomyRequestForm(target);
	AForm *result = static_cast<AForm *>(form);
	return result;
}

AForm * Intern::createPresidentialForm(std::string target) {
	PresidentialPardonForm * form = new PresidentialPardonForm(target);
	AForm *result = static_cast<AForm *>(form);
	return result;
}
