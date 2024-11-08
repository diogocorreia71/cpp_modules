#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T> {}
		MutantStack(MutantStack const &other) : std::stack<T> 
		{
			*this = other;
		}
		MutantStack &operator=(MutantStack const &other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}
};

#endif