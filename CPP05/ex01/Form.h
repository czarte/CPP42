//
// Created by Vojtěch Parkán on 05.09.2025.
//

#ifndef CPP42_FORM_H
#define CPP42_FORM_H

#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
	public:
		Form();
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form & other);
		~Form();
		Form & operator=(const Form & other);
		const std::string getName();
		int getSignGrade();
		int getExecGrade();
		void beSigned(Bureaucrat & bureaucrat);
		bool isSigned();

	class GradeTooLowExeption : virtual public std::exception {
		public:
			const char * what() const throw();
	};

	class GradeTooHighExeption : virtual public std::exception {
		public:
			const char * what() const throw();
	};

};

std::ostream & operator<<(std::ostream &os, Form & form);


#endif //CPP42_FORM_H
