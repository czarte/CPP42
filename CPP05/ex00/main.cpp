#include "Bureaucrat.h"

int main() {
	std::cout << "hello bureaucrat world" << std::endl;
	Bureaucrat b = Bureaucrat("Paul", 1);
	Bureaucrat c = Bureaucrat("Stephane", 151);
//	try {
//		c = Bureaucrat("Stephane", 151);
//	} catch (std::exception & e) {
//		std::cerr << e.what();
//	}
	std::cout << "-----------------" << std::endl;
	std::cout << c;
	std::cout << "-----------------" << std::endl;
	std::cout << b;
	try { b.gradeUp(); } catch (std::exception & e) { std::cerr << "EXEPTION:" << e.what(); throw ; }
	b.gradeDown();
	std::cout << b;
	std::cout << "-----------------" << std::endl;
	b.gradeUp();
	std::cout << b;
	std::cout << "-----------------" << std::endl;
	try { b.gradeUp(); } catch (std::exception & e) {
		std::cerr << e.what();
	}
	try { b.gradeUp(); } catch (std::exception & e) {
		std::cerr << e.what();
	}
	std::cout << b;
	return 0;
}
