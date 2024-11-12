/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:57:11 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/12 14:14:57 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "Subject main:" << std::endl;
	
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	
	std::srand(static_cast<unsigned int>(std::time(0)));

	Span sp_ind(10000);

	std::vector<int> largeVec;
	for (int i = 0; i < 10000; i++)
		largeVec.push_back(std::rand() % 100000);

	try
	{
		sp_ind.addNumbers(largeVec.begin(), largeVec.end());
		std::cout << "Added 10,000 numbers to Span successfully" << std::endl;

		std::cout << "Shortest span: " << sp_ind.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp_ind.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	
	return 0;
}