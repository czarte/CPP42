//
// Created by Vojtěch Parkán on 13.09.2025.
//

#include "ScalarConverter.h"

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
    // Convert to char
    std::cout << "char: ";
    try {
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            char c = literal[0];
            if (std::isprint(c))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        } else {
            double d = std::stod(literal);
            if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
                std::cout << "impossible" << std::endl;
            else if (std::isprint(static_cast<char>(d)))
                std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // Convert to int
    std::cout << "int: ";
    try {
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            std::cout << static_cast<int>(literal[0]) << std::endl;
        } else {
            double d = std::stod(literal);
            if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<int>(d) << std::endl;
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // Convert to float
    std::cout << "float: ";
    try {
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            std::cout << static_cast<float>(literal[0]) << ".0f" << std::endl;
        } else {
            float f = std::stof(literal);
            if (std::isnan(f))
                std::cout << "nanf" << std::endl;
            else if (std::isinf(f))
                std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
            else {
                std::cout << f;
                if (f == static_cast<int>(f))
                    std::cout << ".0";
                std::cout << "f" << std::endl;
            }
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // Convert to double
    std::cout << "double: ";
    try {
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            std::cout << static_cast<double>(literal[0]) << ".0" << std::endl;
        } else {
            double d = std::stod(literal);
            if (std::isnan(d))
                std::cout << "nan" << std::endl;
            else if (std::isinf(d))
                std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
            else {
                std::cout << d;
                if (d == static_cast<int>(d))
                    std::cout << ".0";
                std::cout << std::endl;
            }
        }
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }
}
