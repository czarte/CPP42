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
        CPP02/ex00/Fixed.h
        CPP03/ex00/ClapTrap.cpp
        CPP03/ex00/ClapTrap.h
        CPP03/ex00/main.cpp
        CPP03/ex01/ScavTrap.cpp
        CPP03/ex01/ScavTrap.h
        CPP03/ex01/ScavTrap.h
        CPP03/ex01/ScavTrap.cpp
        CPP03/ex01/ScavTrap.h
        CPP03/ex02/FragTrap.cpp
        CPP03/ex02/FragTrap.h CPP01/ex04/Read.cpp CPP01/ex04/Read.h CPP01/ex04/Write.cpp CPP01/ex04/Write.h
        CPP01/ex04/main.cpp
        CPP04/ex00/main.cpp
        CPP04/ex00/Animal.cpp
        CPP04/ex00/Animal.h
        CPP04/ex00/Dog.cpp
        CPP04/ex00/Dog.h
        CPP04/ex00/Cat.cpp
        CPP04/ex00/Cat.h)
