# CPP42 — 42 School C++ Modules (CPP00–CPP09)

Solutions to the ten C++ modules of the 42 Common Core. Every exercise is written in
**C++98** (`-Wall -Wextra -Werror -std=c++98`) and ships with its own `Makefile`
inside `CPPxx/exNN/`.

```sh
cd CPP03/ex02
make && ./claptrap
```

## Modules

| Module | Topic | Exercises |
|--------|-------|-----------|
| [CPP00](./CPP00) | Namespaces, classes, member functions, stdio streams, initialization lists, `static`, `const` | `ex00` **megaphone** — uppercases its arguments. `ex01` **PhoneBook** — an in-memory phone book with `Contact` entries (`ADD` / `SEARCH` / `EXIT`). |
| [CPP01](./CPP01) | Memory allocation, pointers to members, references, `switch` | `ex00`/`ex01` **Zombie** — stack vs. heap allocation and `zombieHorde`. `ex02` pointer vs. reference to a `std::string`. `ex03` **HumanA/HumanB** — a `Weapon` held by reference vs. pointer. `ex04` **Sed is for losers** — file find-and-replace using `Read`/`Write` classes. `ex05`/`ex06` **Harl** — log-level dispatch via pointers to member functions, then a `switch` with fall-through. |
| [CPP02](./CPP02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | `ex00`–`ex02` **Fixed** — a fixed-point number class built up step by step: canonical form, `int`/`float` conversion, then full arithmetic, comparison, increment and `min`/`max` overloads. |
| [CPP03](./CPP03) | Inheritance | `ex00` **ClapTrap** — base robot with hit points, energy and attack damage. `ex01` **ScavTrap** and `ex02` **FragTrap** — derived classes with their own stats and abilities, showing constructor/destructor chaining. |
| [CPP04](./CPP04) | Subtype polymorphism, abstract classes, interfaces | `ex00` **Animal/Dog/Cat** (+ `WrongAnimal`/`WrongCat`) — virtual vs. non-virtual dispatch. `ex01` adds a heap-allocated **Brain** to demonstrate deep copies and virtual destructors. `ex02` makes `Animal` abstract. |
| [CPP05](./CPP05) | Repetition and exceptions | `ex00` **Bureaucrat** — grade bounds enforced with custom exceptions. `ex01` **Form** — signable by bureaucrats of sufficient grade. `ex02` abstract **AForm** with `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`. `ex03` **Intern** — form factory by name. |
| [CPP06](./CPP06) | C++ casts | `ex00` **ScalarConverter** — parses a literal and converts it to `char`, `int`, `float`, `double` (`static_cast`). `ex01` **Serializer** — pointer ⇄ `uintptr_t` with `reinterpret_cast`. `ex02` identifies the real type behind a `Base*` / `Base&` with `dynamic_cast`. |
| [CPP07](./CPP07) | C++ templates | `ex00` `swap` / `min` / `max` function templates. `ex01` `iter` — applies a function to every element of an array. `ex02` **Array<T>** — a bounds-checked, deep-copying array class template. |
| [CPP08](./CPP08) | Templated containers, iterators, algorithms | `ex00` **easyfind** — finds a value in any STL container. `ex01` **Span** — stores N ints and reports the shortest / longest span. `ex02` **MutantStack** — `std::stack` extended with iterators. |
| [CPP09](./CPP09) | STL | `ex00` **BitcoinExchange** — values a `date \| amount` input file against a `data.csv` price history with `std::map` (closest earlier date lookup). `ex01` **RPN** — evaluates Reverse Polish Notation expressions with `std::stack`. `ex02` **PmergeMe** — Ford-Johnson (merge-insertion) sort over `std::deque` and `std::list` with timing comparison. A full walkthrough of the algorithm, the Jacobsthal insertion order and the bundled tester lives in [`CPP09/ex02/README.md`](./CPP09/ex02/README.md). |

## Layout

```
CPPxx/
└── exNN/
    ├── Makefile
    ├── main.cpp
    └── *.cpp / *.h / *.hpp / *.tpp
```

The root `CMakeLists.txt` exists only so the project can be opened in CLion; the
`Makefile` in each exercise directory is the canonical way to build.
