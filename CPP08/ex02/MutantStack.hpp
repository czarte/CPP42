//
// Created by Vojtěch Parkán on 15.02.2026.
//

#ifndef CPP42_MUTATIONSTACK_HPP
#define CPP42_MUTATIONSTACK_HPP
#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & other);
		MutantStack<T>& operator=(const MutantStack<T> & src);

		typedef typename std::stack<T>::container_type iterable_stack;
		typedef typename iterable_stack::iterator iterator;
		typedef typename iterable_stack::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif //CPP42_MUTATIONSTACK_HPP
