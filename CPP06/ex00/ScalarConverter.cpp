//
// Created by Vojtěch Parkán on 13.09.2025.
//

#include "ScalarConverter.h"
#include <limits>
#include <sstream>
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
    return true;
}

ScalarType decideType(const std::string& s) {
  if (isAllDigits(s)) {
    return INT;
  } else if (hasPointAndSuffix(s)) {
    return FLOAT;
  } else if (hasOnlyPoint(s)) {
    return DOUBLE;
  }
  return CHAR;
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
	std::istringstream iss(literal);
	int i;
	iss >> i;
  	switch (decideType(literal)) {
        case CHAR:
            std::cout << "char: ";
    		try {
    		   	if (std::isprint(i))
    		        std::cout << "'" << (char) i << "'" << std::endl;
				else
   		            std::cout << "Non displayable" << std::endl;
    		} catch (...) {
    			std::cout << "impossible" << std::endl;
			}
            std::cout << "int: " << static_cast<int>(i) << std::endl;
            std::cout << "float: " << static_cast<float>(i) << std::endl;
            std::cout << "double: " << static_cast<float>(i) << std::endl;
        break;
        case INT:
          	std::cout << "char: ";
          	if (i > -128 && i <= 127) {
    		        if (std::isprint(i))
    		            std::cout << "'" << (char) i << "'" << std::endl;
     		       else
   		             std::cout << "Non displayable" << std::endl;
    		} else
                  std::cout << "impossible" << std::endl;
        	std::cout << "int: ";
    		try {
    		    if (i > INT_MIN && i < INT_MAX) {
    		        std::cout << i << std::endl;
    		    }
    		} catch (...) {
    			    std::cout << "impossible" << std::endl;
    		}
            std::cout << "float: " << static_cast<float>(i) << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        break;
        case FLOAT:
          		std::cout << "char: ";
          		if (i > -128 && i <= 127) {
    		        if (std::isprint(i))
    		            std::cout << "'" << (char) i << "'" << std::endl;
     		       else
   		             std::cout << "Non displayable" << std::endl;
    			} else
                  std::cout << "impossible" << std::endl;
        		std::cout << "int: ";
    			try {
    		    	if (i > INT_MIN && i < INT_MAX) {
    		     		std::cout << i << std::endl;
    		   		}
    			} catch (...) {
    			    std::cout << "impossible" << std::endl;
    			}
                std::cout << "float: ";
    			try {
      				std::istringstream iss(literal);
					float f;
        			iss >> f;
        			if (typeid(f) == typeid(float)) {
          				std::cout << f << "f" << std::endl;
        			}
    			} catch (...) {
    				std::cout << "impossible" << std::endl;
   				}
                std::cout << "double: " << static_cast<double>(i) << std::endl;
        break;
        case DOUBLE:
            std::cout << "double: ";
 			try {
      			std::istringstream iss(literal);
				double d;
        		iss >> d;
        		if (typeid(d) == typeid(double)) {
           			std::cout << d << std::endl;
        		}
    		} catch (...) {
 		       	std::cout << "impossible" << std::endl;
    		}
		break;
  	}


}
