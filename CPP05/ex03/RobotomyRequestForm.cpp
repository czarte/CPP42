//
// Created by Vojtěch Parkán on 06.09.2025.
//

#include "RobotomyRequestForm.h"

int RobotomyRequestForm::order = 0;

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", 72, 45)
		, target("default_target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
		: AForm(other), target(other.target)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & other) {
	this->target = other.target;
	return (*this);
}

const std::string RobotomyRequestForm::getName() const {
	return AForm::getName();
}

int RobotomyRequestForm::getSignGrade() {
	return AForm::getSignGrade();
}

int RobotomyRequestForm::getSignGrade() const {
	return AForm::getSignGrade();
}

int RobotomyRequestForm::getExecGrade() {
	return AForm::getExecGrade();
}

int RobotomyRequestForm::getExecGrade() const {
	return AForm::getExecGrade();
}

void RobotomyRequestForm::beSigned(Bureaucrat & bureaucrat) {
	AForm::beSigned(bureaucrat);
}

bool RobotomyRequestForm::isSigned() {
	return AForm::isSigned();
}

bool RobotomyRequestForm::isSigned() const {
	return AForm::isSigned();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	Bureaucrat exec = static_cast<Bureaucrat>(executor);
	this->debug_execution(exec);
	if ((exec.getGrade() <= this->getExecGrade()) && this->isSigned())  {
		std::cout << exec.getName() << " executed " << this->getName() << std::endl;
		if (this->order % 2 == 0)
			std::cout << "GRRRR VRRRR VRUUUUUM: " << this->target << " has been Robotomized!!!!!" << std::endl;
		else
			std::cout << "ERROR: Robotomization failed! Try again..." << std::endl;
		this->order++;
	}
}

std::ostream& operator<<(std::ostream &os, RobotomyRequestForm & form) {
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

const char * RobotomyRequestForm::GradeTooLowExeptionToCreate::what() const throw() {
	return "RobotomyRequestForm exeption: Grades for this Form are out of bounds: minimum is execution grade > 45 and signing grade > 72\n";
}

void RobotomyRequestForm::debug_execution(Bureaucrat exec) const {
	if (DEBUG)
		std::cout
			<< "-----------------debug execution of form------------------" << std::endl
			<< "is signed: " << this->isSigned() << ", exec grade: " << this->getExecGrade() << std::endl
			<< exec
			<< "---------------end of debug form execution----------------" << std::endl;
}