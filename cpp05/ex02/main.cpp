/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:44:58 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/10 14:37:58 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		Form form1("Form1", 50, 50);
		Form form2("Form2", 1, 1);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "Bob tries to sign Form1:" << std::endl;
		b2.signForm(form1);

		std::cout << "Alice tries to sign Form1:" << std::endl;
		b1.signForm(form1);

		std::cout << "Bob tries to sign Form2:" << std::endl;
		b2.signForm(form2);

		std::cout << "Alice tries to sign Form2:" << std::endl;
		b1.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	try
	{
		std::cout << "Attempt to create a form with invalid grade requirements:" << std::endl;
		Form invalidForm("InvalidForm", 0, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	return 0;
}