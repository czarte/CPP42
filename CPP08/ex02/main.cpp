#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "front: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::list<int> lstack;
	lstack.push_back(17);
	lstack.push_back(5);
	std::cout << "front: " << lstack.front() << std::endl;
	lstack.pop_back();
	std::cout << "size: " << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> k(lstack);
	return 0;
}
