#include "Bureaucrat.h"

int main() {
	std::cout << "hello bureaucrat world" << std::endl;
	Bureaucrat b = Bureaucrat("Paul");
	b.gradeDown();
	std::cout << b;
	b.gradeUp();
	b.gradeUp();
	b.gradeUp();
	std::cout << b;
	return 0;
}
