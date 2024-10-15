/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:43 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/15 09:52:42 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &other)
	{
		
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"pardon request", "robotomy request", "shrubbery request"};
	AForm *(Intern::*func_ptr[3])(std::string target) = {&Intern::makePardon, &Intern::makeRobotomy, &Intern::makeShrubbery};
	
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			AForm *form_ptr = (this->*func_ptr[i])(target);
			std::cout << "Intern creates " << form_ptr->getName() << std::endl;
			return form_ptr;
		}
	}
	throw WrongForm();
}

AForm *Intern::makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

const char *Intern::WrongForm::what() const throw()
{
	return "Form not found";
}
