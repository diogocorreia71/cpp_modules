/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:44:58 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/14 12:31:03 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 5);
		Bureaucrat bob("Bob", 45);
		Bureaucrat charlie("Charlie", 140);

		RobotomyRequestForm robotForm("Bender");
		ShrubberyCreationForm shrubForm("Garden");
		PresidentialPardonForm pardonForm("John Doe");
		
		std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
		std::cout << shrubForm << std::endl;
		shrubForm.beSigned(charlie);
		shrubForm.execute(charlie);

		std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
		std::cout << robotForm << std::endl;
		robotForm.beSigned(bob);
		robotForm.execute(bob);

		std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
		std::cout << pardonForm << std::endl;
		pardonForm.beSigned(alice);
		pardonForm.execute(alice);

		std::cout << "\n=== Testing Exception Handling ===" << std::endl;
		PresidentialPardonForm unsignedPardon("Unsigned Pardon");
		alice.executeForm(unsignedPardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	try
	{
		std::cout << "\n=== Testing Invalid Form Creation ===" << std::endl;
		ShrubberyCreationForm invalidForm("InvalidTarget"); 
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	return 0;
}