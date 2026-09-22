//
// Created by Vojtěch Parkán on 05.09.2025.
//

#include "Form.h"
#include "Bureaucrat.h"


Form::Form() : name("Default"), sign_grade(1), exec_grade(150) {}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false)
{
	if (exec_grade < 1 || sign_grade < 1)
		throw GradeTooHighExeption();
	if (exec_grade > 150 || sign_grade > 150)
		throw GradeTooLowExeption();
}

Form::Form(const Form & other)
	: name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade), is_signed(false)
{
}

Form &Form::operator=(const Form & other) {
	if (this == &other)
          return *this;

	return (*this);
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

bool Form::isSigned() {
	return this->is_signed;
}

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade()) {
		this->is_signed = true;
	}
	if (bureaucrat.getGrade() > this->getSignGrade()) {
		throw GradeTooLowExeption();
	}
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
	return "Grade of Burreaucrat is too low to sign the Form\n";
}

const char * Form::GradeTooHighExeption::what() const throw() {
	return "Grade of Form too high\n";
}
