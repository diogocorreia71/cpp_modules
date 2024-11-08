/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:57:11 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/08 11:15:53 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Span sp(10000);

	std::vector<int> largeVec;
	for (int i = 0; i < 10000; i++)
		largeVec.push_back(std::rand() % 100000);

	try
	{
		sp.addNumbers(largeVec.begin(), largeVec.end());
		std::cout << "Added 10,000 numbers to Span successfully" << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	return 0;
	
	
	// Span sp = Span(5);
	
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}