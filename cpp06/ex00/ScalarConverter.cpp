/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:51 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/16 17:41:36 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::Type ScalarConverter::identifyType(const std::string &literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	char *end;
	std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0')
		return INT;
	if (literal.find('f') != std::string::npos && literal.back() == 'f')
		return FLOAT;
	std::strtod(literal.c_str(), &end);
	if (*end == '\0')
		return DOUBLE;
	return INVALID;
}

void ScalarConverter::convertChar(const std::string &literal)
{
	std::cout << "Converting as char: " << literal[0] << std::endl;
}

void ScalarConverter::convertInt(const std::string &literal)
{
	std::cout << "Converting as int: " << std::stoi(literal) << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal)
{
	std::cout << "Converting as float: " << std::stof(literal) << "f" << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal)
{
	std::cout << "Converting as double: " << std::stod(literal) << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	switch (identifyType(literal))
	{
		case CHAR:
			convertChar(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
			break;
		default:
			std::cerr << "Invalid literal!" << std::endl;
			break;
	}
}