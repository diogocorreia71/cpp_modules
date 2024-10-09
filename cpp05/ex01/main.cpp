/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:44:58 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/09 12:11:06 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Arnaldo", 1);
		Bureaucrat b2("Benancio", 150);
		Bureaucrat b3("Carlos", 75);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;

		std::cout << "Incrementing Carlos' grade:" << std::endl;
		b3.incrementGrade();
		std::cout << b3 << std::endl;

		std::cout << "Decrementing Benancio's grade:" << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;

		std::cout << "Trying to increment Arnaldo's grade (which is already 1):" << std::endl;
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Trying to create a Bureaucrat with a grade of 0:" << std::endl;
		Bureaucrat b4("Invalid", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying to create a Bureaucrat with a grade of 151:" << std::endl;
		Bureaucrat b5("Invalid", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	return 0;
}