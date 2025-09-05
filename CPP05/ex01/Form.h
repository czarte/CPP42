//
// Created by Vojtěch Parkán on 05.09.2025.
//

#ifndef CPP42_FORM_H
#define CPP42_FORM_H

#include <iostream>

class Form {
	private:
		std::string name;
		bool is_signed;
		const int sign_grade;
		const int exec_grade;
//		const int order;
//		static int counter;
	public:
		Form();
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form & other);
		~Form();
		const Form & operator=(const Form & other);
		const std::string getName();
		int getSignGrade();
		int getExecGrade();
//		int getOrder();
		void setSignGrade(const int grade);
		void setExecGrade(const int grade);

	class GradeTooLowExeption : virtual public std::exception {
		public:
			const char * what() const throw();
	};

	class GradeTooHighExeption : virtual public std::exception {
		public:
			const char * what() const throw();
	};

};

//int Form::counter = 0;

std::ostream & operator<<(std::ostream &os, Form & form);


#endif //CPP42_FORM_H
