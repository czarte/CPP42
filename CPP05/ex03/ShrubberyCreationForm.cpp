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
		std::string target
)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

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

const std::string ShrubberyCreationForm::getName() const {
	return AForm::getName();
}

int ShrubberyCreationForm::getSignGrade() {
	return AForm::getSignGrade();
}

int ShrubberyCreationForm::getSignGrade() const {
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
		std::cout << exec.getName() << " executed " << this->getName() << std::endl;
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
	} else {
		if (exec.getGrade() > this->getExecGrade())
			throw GradeTooLowExecuteExeptionToCreate();
		if (!this->isSigned())
			throw FormNotSignedException();
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

const char * ShrubberyCreationForm::GradeTooLowExecuteExeptionToCreate::what() const throw() {
	return "ShrubberyCreationForm exeption: Grade of Burreaucrat is too low to execute this form\n";
}

const char * ShrubberyCreationForm::FormNotSignedException::what() const throw() {
	return "ShrubberyCreationForm exeption: Form is not signed\n";
}

void ShrubberyCreationForm::debug_execution(Bureaucrat exec) const {
	if (DEBUG)
		std::cout
			<< "-----------------debug execution of form------------------" << std::endl
			<< "is signed: "
			<< this->isSigned()
			<< ", sign grade: "
			<< this->getSignGrade()
			<< ", exec grade: "
			<< this->getExecGrade()
			<< std::endl
			<< exec
			<< "---------------end of debug form execution----------------" << std::endl;
}