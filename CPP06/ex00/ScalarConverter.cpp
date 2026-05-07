//
// Created by Vojtěch Parkán on 13.09.2025.
//

#include "ScalarConverter.h"
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <typeinfo>

template <typename T>
bool is_pos_inf(T num) {
    return num ==  std::numeric_limits<T>::infinity();
}

template <typename T>
bool is_neg_inf(T num) {
    return num == -std::numeric_limits<T>::infinity();
}

bool isAllDigits(const std::string& str) {
	for (unsigned int i = 0; i < str.length(); i++) {
          if (i == 0 && str[i] == '-')
            continue;
          if (!isdigit(str[i])) {
            return false;
          }
	}
    return true;
}

bool hasPointAndSuffix(const std::string& str) {
  int points = 0;

  if (str[str.length() -1] != 'f')
    return false;

  for (unsigned int i = 0; i < str.length(); i++) {
    if (i == 0 && str[i] == '-')
            continue;
	if(str[i] == '.') {
          points++;
	}
  }
  if (points != 1) {
    return false;
  }
  return true;
}

bool hasOnlyPoint(const std::string& str) {
  	int points = 0;

	for (unsigned int i = 0; i < str.length(); i++) {
          if (i == 0 && str[i] == '-')
            continue;
          if (str[i] == '.') {
            points++;
          } else if (!isdigit(str[i])) {
            return false;
          }
	}
	if (points == 1)
    	return true;
	else
		return false;
}

int getPrecision(const std::string & s) {
	int first = s.find(".") + 1;
	int second = s.find("f");
	std::string ns = s.substr(first, second - first);
	return ns.length();
}

ScalarType decideType(const std::string& s) {
	if (isAllDigits(s)) {
		return INT;
	} else if (s.length() == 1) {
		return CHAR;
	} else if (hasPointAndSuffix(s)) {
		return FLOAT;
	} else if (hasOnlyPoint(s)) {
		return DOUBLE;
	} else if ((s == "+inff") || (s == "-inff") || (s == "nanf") || (s == "+inf") || (s == "-inf") || (s == "nan")) {
		return PSEUDO_LITERAL;
	}
	return INVALID;
}

double ScalarConverter::to_double(const std::string &s, bool &ok) {
    std::istringstream iss(s);
    double val;
    iss >> val;
    ok = (!iss.fail() && iss.eof());
    return val;
}

float ScalarConverter::to_float(const std::string &s, bool &ok) {
    std::istringstream iss(s);
    float val;
    iss >> val;
    ok = (!iss.fail() && iss.eof());
    return val;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	int i = 0;
	char ch = 'a';
	float f = 0.0f;
	double d = 0.0;
	int p = 1;
	char *endptr = NULL;
	std::istringstream iss(literal);

  	switch (decideType(literal)) {
		case CHAR:
			ch = literal[0];
			std::cout << "char: ";
			try {
				if (std::isprint(ch))
					std::cout << "'" << ch << "'" << std::endl;
				else
					std::cout << "Non displayable" << std::endl;
			} catch (...) {
				std::cout << "impossible" << std::endl;
			}
			std::cout << std::fixed << std::setprecision(p);
			std::cout << "int: " << static_cast<int>(ch) << std::endl;
			std::cout << "float: " << static_cast<float>(ch) << 'f' << std::endl;
			std::cout << "double: " << static_cast<float>(ch) << std::endl;
		break;
		case INT:
			iss >> i;
			std::cout << "char: ";
			try {
				if (std::isprint(static_cast<char>(i)))
					std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
				else
					std::cout << "Non displayable" << std::endl;
			} catch (...) {
				std::cout << "impossible" << std::endl;
			}
			std::cout << "int: ";
			try {
				if (i > INT_MIN && i < INT_MAX) {
					std::cout << i << std::endl;
				}
			} catch (...) {
					std::cout << "impossible" << std::endl;
			}
			std::cout << std::fixed << std::setprecision(p);
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		break;
		case FLOAT:
				f = strtof(literal.c_str(), &endptr);
				p = getPrecision(literal);
				std::cout << "char: ";
				ch = static_cast<char>(static_cast<int>(round(f)));
				if (i > -128 && i <= 127) {
					if (std::isprint(ch))
						std::cout << "'" << ch << "'" << std::endl;
				   else
					 std::cout << "Non displayable" << std::endl;
				} else
				  std::cout << "impossible" << std::endl;
				std::cout << "int: ";
				try {
					if (static_cast<int>(f) > INT_MIN && static_cast<int>(f) < INT_MAX) {
						std::cout << static_cast<int>(f) << std::endl;
					}
				} catch (...) {
					std::cout << "impossible" << std::endl;
				}
				std::cout << "float: ";
				std::cout << std::fixed << std::setprecision(p);
				std::cout << f << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
		break;
		case DOUBLE:
			f = strtof(literal.c_str(), &endptr);
			p = getPrecision(literal);
			std::cout << "char: ";
			ch = static_cast<char>(static_cast<int>(round(f)));
			if (i > -128 && i <= 127) {
				if (std::isprint(ch))
					std::cout << "'" << ch << "'" << std::endl;
				else
					std::cout << "Non displayable" << std::endl;
			} else
				std::cout << "impossible" << std::endl;
			std::cout << "int: ";
			try {
				if (static_cast<int>(f) > INT_MIN && static_cast<int>(f) < INT_MAX) {
					std::cout << static_cast<int>(f) << std::endl;
				}
			} catch (...) {
				std::cout << "impossible" << std::endl;
			}
			std::cout << "float: ";
			std::cout << std::fixed << std::setprecision(p);
			std::cout << f << "f" << std::endl;
			std::cout << "double: ";
			d = static_cast<double>(f);
			try {
				if (typeid(d) == typeid(double)) {
					std::cout << d << std::endl;
				}
			} catch (...) {
				std::cout << "impossible" << std::endl;
			}
		break;
		case PSEUDO_LITERAL:
			if (literal == "nan" || literal == "nanf") {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << "nanf" << std::endl;
				std::cout << "double: " << "nan" << std::endl;
			}
			if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << "+inff" << std::endl;
				std::cout << "double: " << "+inf" << std::endl;
			}
			if (literal == "-inf" || literal == "-inff") {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << "-inff" << std::endl;
				std::cout << "double: " << "-inf" << std::endl;
			}
		break;
		case INVALID:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		break;
  	}


}
