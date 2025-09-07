#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "AForm.h"
#include "Intern.h"

int main() {
	std::cout << "hello bureaucrat world" << std::endl;
	Bureaucrat minister = Bureaucrat("Ministry of justice", 5);
	Intern intern;
	AForm *a = intern.makeForm("shrubery", "home");
	minister.signForm(*a);
	a->execute(minister);

//	Bureaucrat b = Bureaucrat("Paul", 51);
//	ShrubberyCreationForm c;
//	RobotomyRequestForm robo = RobotomyRequestForm("Beebox");
//	PresidentialPardonForm pp = PresidentialPardonForm("Lolipop");
//	Bureaucrat minister = Bureaucrat("Ministry of justice", 5);
//	minister.signForm(pp);
//	pp.execute(minister);
//	std::cout << c;
//	try {
//		Bureaucrat c = Bureaucrat("Stephane", 151);
//	} catch (std::exception & e) {
//		std::cerr << e.what();
//	}
//	Bureaucrat shrubbery_bad_signer = Bureaucrat("Shrubbery Bad Signer", 51);
//	Bureaucrat shrubbery_good_signer = Bureaucrat("Shrubbery Good Signer", 40);
//	try {
//		shrubbery_good_signer.signForm(robo);
//		robo.execute(shrubbery_good_signer);
//	} catch (std::exception & e) {
//		std::cerr << e.what();
//	}
//	try {
//		ShrubberyCreationForm d = ShrubberyCreationForm("shrubery");
//		std::cout << d;
//		AForm *da = dynamic_cast<AForm*>(&d);
//		try {
//			shrubbery_bad_signer.signForm(*da);
//		} catch (std::exception & e) {
//			std::cerr << e.what();
//		}
//		b.signForm(*da);
//		try {
//			shrubbery_good_signer.signForm(*da);
//			da->execute(shrubbery_good_signer);
//		} catch (std::exception & e) {
//			std::cerr << e.what();
//		}
//	} catch (std::exception & e) {
//		std::cerr << e.what();
//	}
//	b.gradeDown();
//	std::cout << b;
//	b.gradeUp();
//	std::cout << b;
//	try { b.gradeUp(); } catch (std::exception & e) {
//		std::cerr << e.what();
//	}
//	try { b.gradeUp(); } catch (std::exception & e) {
//		std::cerr << e.what();
//	}
//	std::cout << b;
	//try { b.signForm(d); } catch (std::exception & e) { std::cerr << e.what(); }
	return 0;
}
