/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:00:35 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/14 13:32:35 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery", 145, 137)
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
	std::cout << "Shrubbery constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
	this->_target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

void ShrubberyCreationForm::executor() const
{
	std::string file(_target + "_shrubbery");
	std::ofstream outputFile(file.c_str());
	if (outputFile.fail())
	{
		std::cerr << "Error: Could not create shrubbery file" << std::endl;
		return;
	}
	outputFile << "      /\\\n";
    outputFile << "     /\\*\\\n";
    outputFile << "    /\\O\\*\\\n";
    outputFile << "   /*/\\/\\/\\\n";
    outputFile << "  /\\O\\/\\*\\/\\\n";
    outputFile << " /\\*\\/\\*\\/\\/\\\n";
    outputFile << "/\\O\\/\\/*/\\/O/\\\n";
    outputFile << "      ||\n";
    outputFile << "      ||\n";
    outputFile << "      ||\n";
	outputFile.close();
	std::cout << "Shrubbery created for target: " << _target << std::endl;
}
