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
	ShrubberyCreationForm d = ShrubberyCreationForm("B51", 50, 150, "shrubery");
	std::cout << d;
	AForm *da = dynamic_cast<AForm*>(&d);
	b.signForm(*da);
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
	try { b.signForm(d); } catch (std::exception & e) { std::cerr << e.what(); }
	return 0;
}
