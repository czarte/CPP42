//
// Created by Vojtěch Parkán on 26.04.2026.
//

#ifndef CPP42_RPN_HPP
#define CPP42_RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <exception>

class RPN {
private:
	std::stack<double> _stack;
	void _execute(double (RPN::*f)(double, double));
	double _plus(double a, double b);
	double _minus(double a, double b);
	double _multi(double a, double b);
	double _divide(double a, double b);
public:
	RPN();
	RPN(const std::string &input);
	RPN(const RPN & src);
	RPN &operator=(const RPN & src);
	~RPN();

	double getResult() const;

	class invalidArgument : public std::runtime_error {
	public:
		explicit invalidArgument(const std::string & msg);
	};

	class emptyStack : public std::runtime_error {
	public:
		explicit emptyStack(const std::string & msg);
	};

	class divisionZero : public std::runtime_error {
	public:
		explicit divisionZero(const std::string & msg);
	};

};


#endif //CPP42_RPN_HPP
