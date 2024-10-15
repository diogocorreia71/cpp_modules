/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:44:58 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/15 11:53:23 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Intern intern;
		std::cout << "\n--- Intern created ---\n" << std::endl;

		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat charlie("Charlie", 150);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;

		AForm* shrubberyForm = intern.makeForm("shrubbery request", "Garden");
		AForm* robotomyForm = intern.makeForm("robotomy request", "Bender");
		AForm* pardonForm = intern.makeForm("pardon request", "John Doe");

		if (shrubberyForm)
		{
			std::cout << "\n--- Shrubbery Form ---\n";
            std::cout << *shrubberyForm << std::endl;
            charlie.signForm(*shrubberyForm);
            charlie.executeForm(*shrubberyForm);
            bob.signForm(*shrubberyForm);
            bob.executeForm(*shrubberyForm);
            delete shrubberyForm;
		}
		
		if (robotomyForm)
		{
            std::cout << "\n--- Robotomy Form ---\n";
            std::cout << *robotomyForm << std::endl;
            bob.signForm(*robotomyForm);
            bob.executeForm(*robotomyForm);
            alice.executeForm(*robotomyForm);
            delete robotomyForm;
        }

		if (pardonForm)
		{
            std::cout << "\n--- Pardon Form ---\n";
            std::cout << *pardonForm << std::endl;
            bob.signForm(*pardonForm);
            alice.signForm(*pardonForm);
            alice.executeForm(*pardonForm);
            delete pardonForm;
        }
		
		AForm* invalidForm = intern.makeForm("unknown request", "Nobody");

		if (invalidForm)
		{
            delete invalidForm;
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	return 0;
}