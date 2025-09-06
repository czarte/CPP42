//
// Created by Vojtěch Parkán on 06.09.2025.
//

#ifndef CPP42_SHRUBBERYCREATIONFORM_H
#define CPP42_SHRUBBERYCREATIONFORM_H

#include "AForm.h"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name, int sign_grade, int exec_grade, std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & other);
		const std::string getName();
		int getSignGrade();
		int getExecGrade();
		void beSigned(Bureaucrat & bureaucrat);
		bool isSigned();
};

std::ostream & operator<<(std::ostream &os, ShrubberyCreationForm & form);

#endif //CPP42_SHRUBBERYCREATIONFORM_H
