//
// Created by Vojtěch Parkán on 06.09.2025.
//

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", 25, 5)
		, target("default_target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
		: AForm(other), target(other.target)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & other) {
	this->target = other.target;
	return (*this);
}

const std::string PresidentialPardonForm::getName() const {
	return AForm::getName();
}

int PresidentialPardonForm::getSignGrade() {
	return AForm::getSignGrade();
}

int PresidentialPardonForm::getExecGrade() {
	return AForm::getExecGrade();
}

int PresidentialPardonForm::getExecGrade() const {
	return AForm::getExecGrade();
}

void PresidentialPardonForm::beSigned(Bureaucrat & bureaucrat) {
	AForm::beSigned(bureaucrat);
}

bool PresidentialPardonForm::isSigned() {
	return AForm::isSigned();
}

bool PresidentialPardonForm::isSigned() const {
	return AForm::isSigned();
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	Bureaucrat exec = static_cast<Bureaucrat>(executor);
	this->debug_execution(exec);
	if ((exec.getGrade() <= this->getExecGrade()) && this->isSigned())  {
		std::cout << exec.getName() << " executed " << this->getName() << std::endl;
		std::cout << "We want to Inform You, that "
			<< this->target
			<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, PresidentialPardonForm & form) {
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

const char * PresidentialPardonForm::GradeTooLowExeptionToCreate::what() const throw() {
	return "PresidentialPardonForm exeption: Grades for this Form are out of bounds: minimum is execution grade > 45 and signing grade > 72\n";
}

void PresidentialPardonForm::debug_execution(Bureaucrat exec) const {
	if (DEBUG)
		std::cout
			<< "-----------------debug execution of form------------------" << std::endl
			<< "is signed: " << this->isSigned() << ", exec grade: " << this->getExecGrade() << std::endl
			<< exec
			<< "---------------end of debug form execution----------------" << std::endl;
}
