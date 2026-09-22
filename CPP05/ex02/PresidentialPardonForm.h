//
// Created by Vojtěch Parkán on 06.09.2025.
//

#ifndef CPP42_PRESIDENTIALPARDONFORM_H
#define CPP42_PRESIDENTIALPARDONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class PresidentialPardonForm : public AForm {
private:
	std::string target;
	static int order;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm & other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm & other);
	const std::string getName() const;
	int getSignGrade();
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
};

std::ostream & operator<<(std::ostream &os, PresidentialPardonForm & form);


#endif //CPP42_PRESIDENTIALPARDONFORM_H
