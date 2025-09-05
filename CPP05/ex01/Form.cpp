//
// Created by Vojtěch Parkán on 05.09.2025.
//

#include "Form.h"

Form::Form() : name("Default"), sign_grade(1), exec_grade(150) {
	this->counter++;

}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (exec_grade < 1 || sign_grade < 1)
		throw GradeTooHighExeption();
	if (exec_grade > 150 || sign_grade > 150)
		throw GradeTooLowExeption();
}

Form::Form(const Form & other)
	: sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	if (this != &other) {
		this->name = other.name;
	}
}

Form::~Form() {}

int Form::getSignGrade() {
	return this->sign_grade;
}
int Form::getExecGrade() {
	return this->exec_grade;
}

const std::string Form::getName() {
	return this->name;
}

std::ostream& operator<<(std::ostream &os, Form & form) {
	os
		<< "------------Form---------------" << std::endl
		<< "The form "
		<< form.getName()
		<< ", grade required to sign "
		<< form.getSignGrade()
		<< " grade required to execute "
		<< form.getExecGrade()
		<< std::endl
		<< "-------------------------------" << std::endl;
	return os;
}

const char * Form::GradeTooLowExeption::what() const throw() {
	return "Grade too low\n";
}

const char * Form::GradeTooHighExeption::what() const throw() {
	return "Grade too high\n";
}
