//
// Created by Vojtěch Parkán on 13.09.2025.
//

#include "ScalarConverter.h"
#include <limits>
#include <sstream>

template <typename T>
bool is_pos_inf(T num) {
    return num ==  std::numeric_limits<T>::infinity();
}

template <typename T>
bool is_neg_inf(T num) {
    return num == -std::numeric_limits<T>::infinity();
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
    // Convert to char
    std::cout << "char: ";
    bool ok;
    try {
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            char c = literal[0];
            if (std::isprint(c))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        } else {
            double d = to_double(literal, ok);
            if (ok && (d < 0 || d > 127 || !std::isdigit(d) || is_pos_inf(d) || is_neg_inf(d)))
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
            double d = to_double(literal, ok);
            if (ok && (d < INT_MIN || d > INT_MAX || !std::isdigit(d) || is_pos_inf(d) || is_neg_inf(d)))
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
            double f = to_double(literal, ok);
            if (ok && !std::isdigit(f))
                std::cout << "nanf" << std::endl;
            else if (ok && (is_pos_inf(f) || is_neg_inf(f)))
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
            double d = to_double(literal, ok);
            if (ok && !std::isdigit(d))
                std::cout << "nan" << std::endl;
            else if (ok && (is_pos_inf(d) || is_neg_inf(d)))
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
