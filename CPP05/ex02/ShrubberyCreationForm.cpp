//
// Created by Vojtěch Parkán on 06.09.2025.
//

#include "ShrubberyCreationForm.h"
#include <fstream>

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
		throw GradeTooLowExeptionToCreate();
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

int ShrubberyCreationForm::getExecGrade() const {
	return AForm::getExecGrade();
}

void ShrubberyCreationForm::beSigned(Bureaucrat & bureaucrat) {
	AForm::beSigned(bureaucrat);
}

bool ShrubberyCreationForm::isSigned() {
	return AForm::isSigned();
}

bool ShrubberyCreationForm::isSigned() const {
	return AForm::isSigned();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	Bureaucrat exec = static_cast<Bureaucrat>(executor);
	this->debug_execution(exec);
	if ((exec.getGrade() <= this->getExecGrade()) && this->isSigned())  {
		std::ofstream outFile(this->target);
		if (!outFile) {
			std::cerr << "Error opening file for writing!" << std::endl;
			return;
		}
		std::cout << "execute the shrubbery form, printing into file '" << this->target << "'" << std::endl;
		outFile << "---------------------------------" << std::endl
				<< "|				A				|" << std::endl
				<< "|			   A A				|" << std::endl
				<< "|			  A| |A				|" << std::endl
				<< "|			 A |A| A			|" << std::endl
				<< "|			  A| |A				|" << std::endl
				<< "|			 A | | A			|" << std::endl
				<< "|			A  | |  A			|" << std::endl
				<< "|			   | |				|" << std::endl
				<< "|			   | |				|" << std::endl
				<< "|			   | |				|" << std::endl
				<< "---------------------------------" << std::endl;
		outFile.close();
	}
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

const char * ShrubberyCreationForm::GradeTooLowExeptionToCreate::what() const throw() {
	return "ShrubberyCreationForm exeption: Grades for this Form are out of bounds: minimum is execution grade > 137 and signing grade > 145\n";
}

void ShrubberyCreationForm::debug_execution(Bureaucrat exec) const {
	std::cout
			<< "-----------------debug execution of form------------------" << std::endl
			<< "is signed: " << this->isSigned() << ", exec grade: " << this->getExecGrade() << std::endl
			<< exec
			<< "---------------end of debug form execution----------------" << std::endl;
}