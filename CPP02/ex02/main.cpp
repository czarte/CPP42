#include "Fixed.h"

int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "a:\t\t" << a << std::endl;
	std::cout << "++a:\t\t" << ++a << std::endl;
	std::cout << "a:\t\t" << a << std::endl;
	std::cout << "a++:\t\t" << a++ << std::endl;
	std::cout << "a:\t\t" << a << std::endl;
	std::cout << "b:\t\t" << b << std::endl;
	std::cout << "a + b:\t\t" << a + b << std::endl;
	std::cout << "a - b:\t\t" << a - b << std::endl;
	std::cout << "--a:\t\t" << --a << std::endl;
	std::cout << "a++:\t\t" << a++ << std::endl;
	std::cout << "a--:\t\t" << a-- << std::endl;
	std::cout << "(a == b):\t" << (a == b) << std::endl;
	std::cout  << "max(a,b):\t" << Fixed::max(a, b) << std::endl;
	std::cout  << "min(a,b):\t" << Fixed::min(a, b) << std::endl;
	return 0;
}
