//
// Created by Vojtěch Parkán on 30.08.2025.
//

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() {
	this->grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name) : name(name) {
	this->grade = 1;

}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : name(other.name), grade(other.grade) {}

const Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream &os, Bureaucrat & bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::gradeUp() {
	try {
		if (--this->grade < 1) {
			this->grade = 1;
			throw GradeTooHighException;
		}
	}
	catch (...) {
		std::cout << "Exeption: Grade is too low" << std::endl;
	}
}

void Bureaucrat::gradeDown() {
	try {
		if (++this->grade > 150) {
			this->grade = 150;
			throw GradeTooLowException;
		}
	}
	catch (...) {
		std::cout << "Exeption: Grade is too low" << std::endl;
	}
}

int Bureaucrat::getGrade() {
	return this->grade;
}

const std::string Bureaucrat::getName() {
	return this->name;
}
