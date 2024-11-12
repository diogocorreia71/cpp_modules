/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:23:49 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/12 09:38:49 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);

	std::deque<int> deq;
	deq.push_back(10);
	deq.push_front(20);
	deq.push_back(30);
	deq.push_front(15);
	
	try
	{
		std::vector<int>::iterator vecIt = easyfind(vec, 20);
		std::cout << "Found in vector: " << *vecIt << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::iterator lstIt = easyfind(lst, 25);
		std::cout << "Found in list: " << *lstIt << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::iterator itLst = easyfind(lst, 2);
		std::cout << "Found int list: " << *itLst << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::deque<int>::iterator deqIt = easyfind(deq, 15);
		std::cout << "Found in deque list: " << *deqIt << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::deque<int>::iterator itDeq = easyfind(deq, 25);
		std::cout << "Found in deque list: " << *itDeq << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
