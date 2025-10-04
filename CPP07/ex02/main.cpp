#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

#define MAX_VAL 7
int main(int, char**)
{
	int * a = new int(10);
    int * w = new int(*a);
    int * t = w;
	std::cout << *a << std::endl;
	Array<int> b = Array<int>(10);
    Array<int> c = b;
    Array<int> d = Array<int>(c);
	a[0] = 1;
	a[1] = 3;
    b[0] = 2;
    b[1] = 4;
    c[0] = 5;
    std::cout << "---------t----------" << std::endl;
    for(int i = 0; i < 9; i++) {
    	std::cout << "[" << t[i] << "], ";
    }
    std::cout << std::endl;
    std::cout << "---------w----------" << std::endl;
    for(int i = 0; i < 9; i++) {
    	std::cout << "[" << w[i] << "], ";
    }
    std::cout << std::endl;
    std::cout << "---------d----------" << std::endl;
    for(int i = 0; i < 9; i++) {
    	std::cout << "[" << d[i] << "], ";
    }
    std::cout << std::endl;
    std::cout << "---------c----------" << std::endl;
    for(int i = 0; i < 9; i++) {
    	std::cout << "[" << c[i] << "], ";
    }
	std::cout << std::endl;
    std::cout << "---------b----------" << std::endl;
    for(int i = 0; i < 9; i++) {
    	std::cout << "[" << b[i] << "], ";
    }
	std::cout << std::endl;
    std::cout << "---------a----------" << std::endl;
    for(int i = 0; i < 9; i++) {
    	std::cout << "[" << a[i] << "], ";
    }
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
		std::cout << numbers[i] << " :: " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
