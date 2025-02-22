#include "Fixed.h"

int main(void) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	std::cout << "a value is: " << a.getRawBits() << std::endl;
	std::cout << "b value is: " << b.getRawBits() << std::endl;
	std::cout << "c value is: " << c.getRawBits() << std::endl;
	return (0);
}
