/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:44:02 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/22 16:53:26 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	srand(std::time(0));
	
	int randNum = rand() % 3;

	if (randNum == 0)
	{
		std::cout << "Generated A" << std::endl;
		return new A();
	}
	else if (randNum == 1)
	{
		std::cout << "Generated B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A type" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B type" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C type" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A type" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B type" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C type" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Base *basePtr = generate();
	
	std::cout << std::endl;
	identify(basePtr);
	std::cout << std::endl;
	identify(*basePtr);
	std::cout << std::endl;

	delete basePtr;

	return 0;
}
