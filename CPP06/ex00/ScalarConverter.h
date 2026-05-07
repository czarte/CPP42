//
// Created by Vojtěch Parkán on 13.09.2025.
//

#ifndef CPP42_SCALARCONVERTER_H
#define CPP42_SCALARCONVERTER_H

#include <iostream>
#include <climits>
#include <string>

enum ScalarType {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  PSEUDO_LITERAL,
  INVALID
};

class ScalarConverter {
    private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
    public:
        ~ScalarConverter();
        static void convert(const std::string& literal);
		static double to_double(const std::string &s, bool &ok);
        static float to_float(const std::string &s, bool &ok);
};


#endif //CPP42_SCALARCONVERTER_H
