#include "custom_types.h"

GradeTooHighExeption::GradeTooHighExeption() {}
GradeTooLowExeption::GradeTooLowExeption() {}

const char *GradeTooHighExeption::what() const throw() {
	return "Grade too high\n";
}

const char *GradeTooLowExeption::what() const throw() {
	return "Grade too low\n";
}
