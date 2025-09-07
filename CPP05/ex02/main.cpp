#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "AForm.h"

int main() {
	std::cout << "hello bureaucrat world" << std::endl;
	Bureaucrat b = Bureaucrat("Paul", 51);
	ShrubberyCreationForm c;
	std::cout << c;
	try {
		Bureaucrat c = Bureaucrat("Stephane", 151);
	} catch (std::exception & e) {
		std::cerr << e.what();
		std::cout << c;
	}
	Bureaucrat shrubbery_bad_signer = Bureaucrat("Shrubbery Bad Signer", 51);
	try {
		ShrubberyCreationForm d = ShrubberyCreationForm("B51", 50, 141, "shrubery");
		std::cout << d;
		AForm *da = dynamic_cast<AForm*>(&d);
		try {
			shrubbery_bad_signer.signForm(*da);
		} catch (std::exception & e) {
			std::cerr << e.what();
		}
		b.signForm(*da);
	} catch (std::exception & e) {
		std::cerr << e.what();
	}
	b.gradeDown();
	std::cout << b;
	b.gradeUp();
	std::cout << b;
	try { b.gradeUp(); } catch (std::exception & e) {
		std::cerr << e.what();
	}
	try { b.gradeUp(); } catch (std::exception & e) {
		std::cerr << e.what();
	}
	std::cout << b;
	//try { b.signForm(d); } catch (std::exception & e) { std::cerr << e.what(); }
	return 0;
}
