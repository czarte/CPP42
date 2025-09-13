//
// Created by Vojtěch Parkán on 05.09.2025.
//

#include "AForm.h"
#include "Bureaucrat.h"


AForm::AForm() : name("Default"), sign_grade(1), exec_grade(150) {}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade)
	: name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (exec_grade < 1 || sign_grade < 1)
		throw GradeTooHighExeption();
	if (exec_grade > 150 || sign_grade > 150)
		throw GradeTooLowExeption();
}

AForm::AForm(const AForm & other)
	: name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
}

AForm::~AForm() {}

int AForm::getSignGrade() {
	return this->sign_grade;
}

int AForm::getSignGrade() const {
	return this->sign_grade;
}

int AForm::getExecGrade() {
	return this->exec_grade;
}

int AForm::getExecGrade() const {
	return this->exec_grade;
}

const std::string AForm::getName() const {
	return this->name;
}

bool AForm::isSigned() {
	return this->is_signed;
}

bool AForm::isSigned() const {
	return this->is_signed;
}

void AForm::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade()) {
		this->is_signed = true;
	}
	if (bureaucrat.getGrade() > this->getSignGrade()) {
		throw GradeTooLowExeption();
	}


}

std::ostream& operator<<(std::ostream &os, AForm & form) {
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

const char * AForm::GradeTooLowExeption::what() const throw() {
	return "Grade of Burreaucrat is too low to sign the Form\n";
}

const char * AForm::GradeTooHighExeption::what() const throw() {
	return "Grade of Form too high\n";
}
