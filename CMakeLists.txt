cmake_minimum_required(VERSION 3.30)
project(CPP01)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP01 ex00/main.cpp
        ex00/Zombie.cpp
        ex00/Zombie.h
        ex00/main.cpp
        ex00/zombieHorde.cpp
        ex02/main.cpp
        ex04/main.cpp
        ex03/main.cpp
        ex03/Weapon.cpp
        ex03/Weapon.h
        ex03/HumanA.cpp
        ex03/HumanA.h
        ex03/HumanB.cpp
        ex03/HumanB.h
        CPP01/ex05/Harl.cpp
        CPP01/ex05/Harl.h
        CPP02/ex00/Fixed.cpp
        CPP02/ex00/Fixed.h)
