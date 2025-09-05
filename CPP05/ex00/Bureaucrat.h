//
// Created by Vojtěch Parkán on 30.08.2025.
//

#ifndef CPP42_BUREAUCRAT_H
#define CPP42_BUREAUCRAT_H
#include <iostream>
#include "custom_types.h"

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat & other);
		~Bureaucrat();
		const Bureaucrat & operator=(const Bureaucrat & other);
		void gradeUp();
		void gradeDown();
		int getGrade();
		void setGrade(int grade);
		const std::string getName();
};

std::ostream & operator<<(std::ostream &os, Bureaucrat & bureaucrat);


#endif //CPP42_BUREAUCRAT_H
