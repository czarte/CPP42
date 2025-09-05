#include "Bureaucrat.h"
#include "Form.h"

int main() {
	std::cout << "hello bureaucrat world" << std::endl;
	Bureaucrat b = Bureaucrat("Paul", 1);
	Form c;
	std::cout << c;
	try {
		Bureaucrat c = Bureaucrat("Stephane", 151);
	} catch (std::exception & e) {
		std::cerr << e.what();
		std::cout << c;
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
	return 0;
}
