//
// Created by Vojtěch Parkán on 06.09.2025.
//

#ifndef CPP42_ROBOTOMYREQUESTFORM_H
#define CPP42_ROBOTOMYREQUESTFORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
		static int order;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & other);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm & other);
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

std::ostream & operator<<(std::ostream &os, RobotomyRequestForm & form);


#endif //CPP42_ROBOTOMYREQUESTFORM_H
