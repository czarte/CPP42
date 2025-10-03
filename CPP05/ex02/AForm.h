//
// Created by Vojtěch Parkán on 05.09.2025.
//

#ifndef CPP42_FORM_H
#define CPP42_FORM_H
#define DEBUG false

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
	public:
		AForm();
		AForm(const std::string name, int sign_grade, int exec_grade);
		AForm(const AForm & other);
		~AForm();
		AForm & operator=(const AForm & other);
		virtual const std::string getName() const = 0;
		virtual int getSignGrade() = 0;
		virtual int getExecGrade() = 0;
		virtual int getExecGrade() const = 0;
		virtual void beSigned(Bureaucrat & bureaucrat) = 0;
		virtual bool isSigned() = 0;
		virtual bool isSigned() const = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual void debug_execution(Bureaucrat exec) const = 0;

	class GradeTooLowExeption : virtual public std::exception {
		public:
			const char * what() const throw();
	};

	class GradeTooHighExeption : virtual public std::exception {
		public:
			const char * what() const throw();
	};

};

std::ostream & operator<<(std::ostream &os, AForm & form);


#endif //CPP42_FORM_H
