//
// Created by Vojtěch Parkán on 06.09.2025.
//

#ifndef CPP42_SHRUBBERYCREATIONFORM_H
#define CPP42_SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & other);
		const std::string getName() const;
		int getSignGrade();
		int getSignGrade() const;
		int getExecGrade();
		int getExecGrade() const;
		void beSigned(Bureaucrat & bureaucrat);
		bool isSigned();
		bool isSigned() const;
		void execute(Bureaucrat const & executor) const;
		void debug_execution(Bureaucrat exec) const;

	class GradeTooLowExeptionToCreate : virtual public std::exception {
	public:
		const char * what() const throw();
	};

	class GradeTooLowExecuteExeptionToCreate : virtual public std::exception {
	public:
		const char * what() const throw();
	};

	class FormNotSignedException : virtual public std::exception {
	public:
		const char * what() const throw();
	};
};

std::ostream & operator<<(std::ostream &os, ShrubberyCreationForm & form);

#endif //CPP42_SHRUBBERYCREATIONFORM_H
