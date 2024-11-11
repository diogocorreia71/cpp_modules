/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:57:11 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/11 15:23:59 by diodos-s         ###   ########.fr       */
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
	
	Span sp_ind = Span(5);
	
	sp_ind.addNumber(6);
	sp_ind.addNumber(3);
	sp_ind.addNumber(17);
	sp_ind.addNumber(9);
	sp_ind.addNumber(11);
	
	std::cout << sp_ind.shortestSpan() << std::endl;
	std::cout << sp_ind.longestSpan() << std::endl;
	
	return 0;
}