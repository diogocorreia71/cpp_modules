/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:23:49 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/07 15:42:01 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

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
	
	try
	{
		std::vector<int>::iterator vecIt = easyfind(vec, 20);
		std::cout << "Found in vector: " << *vecIt << std::endl;

		std::list<int>::iterator lstIt = easyfind(lst, 25);
		std::cout << "Found in list: " << *lstIt << std::endl;

		easyfind(vec, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}


