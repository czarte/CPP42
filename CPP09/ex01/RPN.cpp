//
// Created by Vojtěch Parkán on 26.04.2026.
//

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string & input) {
	std::stringstream ss(input);
	std::string variable;
	int num;

	while (std::getline(ss, variable, ' ')) {
		if ((variable.length() == 1 && isdigit(variable[0])) || (variable.length() == 2 && variable[0] == '-' && isdigit(variable[1]))) {
			std::stringstream(variable) >> num;
			_stack.push(num);
		} else if (variable == "+") {
			_execute(&RPN::_plus);
		} else if (variable == "-") {
			_execute(&RPN::_minus);
		} else if (variable == "*") {
			_execute(&RPN::_multi);
		} else if (variable == "/") {
			_execute(&RPN::_divide);
		} else
			throw RPN::invalidArgument("Error: Invalid argument " + variable);
	}
}

RPN::RPN(const RPN & src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

RPN::invalidArgument::invalidArgument(const std::string &msg) : std::runtime_error(msg) {}
RPN::emptyStack::emptyStack(const std::string &msg) : std::runtime_error(msg) {}
RPN::divisionZero::divisionZero(const std::string &msg) : std::runtime_error(msg) {}

double RPN::getResult() const {
	if (_stack.empty())
		throw RPN::emptyStack("Empty stack");
//	else if (_stack.size() > 1)
//		throw RPN::invalidArgument("Invalid agrument");
	return _stack.top();
}

void RPN::_execute(double (RPN::*f)(double, double)) {
	double a;
	double b;

	if (_stack.size() < 2)
		throw RPN::emptyStack("Empty stack");
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	_stack.push((this->*f)(a, b));
}

double RPN::_plus(double a, double b) {
	return (a + b);
}

double RPN::_minus(double a, double b) {
	return (a - b);
}

double RPN::_multi(double a, double b) {
	return (a * b);
}

double RPN::_divide(double a, double b) {
	if (a == 0)
		throw RPN::divisionZero("Division by zero");
	return (a / b);
}


