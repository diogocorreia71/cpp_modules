/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:37:18 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/31 10:22:07 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main()
{
	Array<int> defaultArray;
	std::cout << "Size of defaultArray: " << defaultArray.size() << std::endl;

	std::cout << std::endl;

	unsigned int size = 5;
	Array<int> paramArray(size);
	std::cout << "Size of paramArray: " << paramArray.size() << std::endl;

	std::cout << std::endl;

	for (unsigned int i = 0; i < size; i++)
		paramArray[i] = i * 10;

	std::cout << "Elements of paramArray: ";
	for (unsigned int i = 0; i < paramArray.size(); i++)
		std::cout << paramArray[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	Array<int> copyArray(paramArray);
	std::cout << "Size of copyArray: " << copyArray.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Elements of copyArray: ";
	for (unsigned int i = 0; i < copyArray.size(); i++)
		std::cout << copyArray[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	Array<int> assignedArray;
	assignedArray = paramArray;
	std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Elements of assignedArray: ";
	for (unsigned int i = 0; i < assignedArray.size(); i++)
		std::cout << assignedArray[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	try
	{
		std::cout << "Attempting to access out-of-bounds element: ";
		std::cout << paramArray[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	
	return 0;
}