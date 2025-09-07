//
// Created by Vojtěch Parkán on 30.08.2025.
//

#include "Bureaucrat.h"
#include "AForm.h"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	try {
		setGrade(grade) ;
	} catch (std::exception & e) {
		std::cerr << e.what();
	}
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
//	if (--this->grade < 1) {
//		this->grade = 1;
//		throw GradeTooHighExeption();
//	}
	try {
		if (--this->grade < 1) {
			this->grade = 1;
			throw GradeTooHighExeption();
		}
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
}

void Bureaucrat::gradeDown() {
//	if (++this->grade > 150) {
//		this->grade = 150;
//		throw GradeTooLowExeption();
//	}
	try {
		if (++this->grade > 150) {
			this->grade = 150;
			throw GradeTooLowExeption();
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what();
	}
}

int const Bureaucrat::getGrade() const {
	return this->grade;
}

int Bureaucrat::getGrade() {
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
	if (grade > 150) {
		this->grade = 150;
		throw GradeTooLowExeption();
	}
	if (grade < 1) {
		this->grade = 1;
		throw GradeTooHighExeption();
	}
	this->grade = grade;
}

const std::string Bureaucrat::getName() {
	return this->name;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout
				<< this->getName()
				<< " signed "
				<< form.getName()
				<< std::endl;
	} catch (std::exception & e) {
		std::cout
				<< this->getName()
				<< " couldn’t sign "
				<< form.getName()
				<< " because "
				<< e.what();
	}
}

const char * Bureaucrat::GradeTooHighExeption::what() const throw() {
	return "Grade too high\n";
}

const char * Bureaucrat::GradeTooLowExeption::what() const throw() {
	return "Grade too low\n";
}
