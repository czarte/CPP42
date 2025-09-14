
#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <__config>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    std::srand(std::time(nullptr));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated C" << std::endl;
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}

int main() {
    std::cout << "Testing generate and identify functions:" << std::endl;

    // Test generate and identify with pointer
    for (int i = 0; i < 3; i++) {
        Base* ptr = generate();
        std::cout << "Pointer identification: ";
        identify(ptr);
        std::cout << "Reference identification: ";
        identify(*ptr);
        std::cout << "---" << std::endl;
        delete ptr;
    }

    return 0;
}
