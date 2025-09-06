//
// Created by Vojtěch Parkán on 06.09.2025.
//

#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
		, target("default_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(
		const std::string name,
		const int sign_grade,
		const int exec_grade,
		std::string target
)
	: AForm(name, sign_grade, exec_grade), target(target)
{
	if (exec_grade < 1 || sign_grade < 1)
		throw GradeTooHighExeption();
	if (exec_grade > 137 || sign_grade > 145)
		throw GradeTooLowExeption();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
		: AForm(other), target(other.target)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other) {
	this->target = other.target;
	return (*this);
}

const std::string ShrubberyCreationForm::getName() {
	return AForm::getName();
}

int ShrubberyCreationForm::getSignGrade() {
	return AForm::getSignGrade();
}

int ShrubberyCreationForm::getExecGrade() {
	return AForm::getExecGrade();
}

void ShrubberyCreationForm::beSigned(Bureaucrat & bureaucrat) {
	AForm::beSigned(bureaucrat);
}
bool ShrubberyCreationForm::isSigned() {
	return AForm::isSigned();
}

std::ostream& operator<<(std::ostream &os, ShrubberyCreationForm & form) {
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
