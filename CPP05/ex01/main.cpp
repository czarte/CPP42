#include "Bureaucrat.h"
#include "Form.h"

int main() {
	std::cout << "hello bureaucrat world" << std::endl;
	Bureaucrat b = Bureaucrat("Paul", 51);
	Form c;
	std::cout << c;
	try {
		Bureaucrat c = Bureaucrat("Stephane", 151);
	} catch (std::exception & e) {
		std::cerr << e.what();
		std::cout << c;
	}
	Form d = Form("B51", 50, 150);
	Form x = d;
    std::cout << "------------X-------------" << std::endl;
    std::cout << x;
	std::cout << "------------D-------------" << std::endl;
    std::cout << d;
	b.signForm(d);
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
