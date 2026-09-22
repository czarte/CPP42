cmake_minimum_required(VERSION 3.30)
project(CPP04)

set(CMAKE_CXX_STANDARD 98)

add_executable(
        CPP04/ex01/main.cpp
        CPP04/ex01/Animal.cpp
        CPP04/ex01/Animal.h
        CPP04/ex01/Dog.cpp
        CPP04/ex01/Dog.h
        CPP04/ex01/Cat.cpp
        CPP04/ex01/Cat.h
        CPP04/ex01/WrongAnimal.cpp
        CPP04/ex01/WrongAnimal.h
        CPP04/ex01/WrongCat.cpp
        CPP04/ex01/WrongCat.h
        CPP04/ex01/Brain.cpp
        CPP04/ex01/Brain.h
        CPP04/ex01/Animal.cpp
        CPP05/ex00/Bureaucrat.cpp
        CPP05/ex00/Bureaucrat.h
        CPP05/ex00/custom_types.h
        CPP05/ex00/main.cpp
        CPP05/ex00/Bureaucrat.cpp
        CPP05/ex00/custom_types.h
        CPP05/ex01/Form.cpp
        CPP05/ex01/Form.h
        CPP05/ex02/ShrubberyCreationForm.cpp
        CPP05/ex02/ShrubberyCreationForm.h
        CPP05/ex02/RobotomyRequestForm.cpp
        CPP05/ex02/RobotomyRequestForm.h
        CPP05/ex02/PresidentialPardonForm.cpp
        CPP05/ex02/PresidentialPardonForm.h
        CPP05/ex03/Intern.cpp
        CPP05/ex03/Intern.h
        CPP06/ex00/ScalarConverter.cpp
        CPP06/ex00/ScalarConverter.h
        CPP08/ex00/EasyFind.h
        CPP08/ex00/main.cpp
        CPP08/ex01/Span.cpp
        CPP08/ex01/Span.hpp
        CPP08/ex02/MutantStack.tpp
        CPP08/ex02/MutantStack.hpp
        CPP09/ex00/BitcoinExchange.cpp
        CPP09/ex00/BitcoinExchange.hpp)
