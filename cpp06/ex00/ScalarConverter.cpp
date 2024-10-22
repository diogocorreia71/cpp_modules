/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:51 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/22 10:58:11 by diodos-s         ###   ########.fr       */
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
	(void)other;
	return *this;
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
	if (literal.find('f') != std::string::npos && literal[literal.length() - 1] == 'f')
		return FLOAT;
	std::strtod(literal.c_str(), &end);
	if (*end == '\0')
		return DOUBLE;
	return INVALID;
}

void ScalarConverter::printCharConversion(double value)
{
	if (std::isnan(value) || std::isinf(value) || 
		value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printIntConversion(double value)
{
	if (std::isnan(value) || std::isinf(value) || 
		value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloatAndDoubleConversion(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convertFromChar(char value)
{
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	printFloatAndDoubleConversion(static_cast<double>(value));
}

void ScalarConverter::convertFromInt(int value)
{
	printCharConversion(static_cast<double>(value));
	std::cout << "int: " << value << std::endl;
	printFloatAndDoubleConversion(static_cast<double>(value));
}

void ScalarConverter::convertFromFloat(float value)
{
	printCharConversion(static_cast<double>(value));
	printIntConversion(static_cast<double>(value));
	printFloatAndDoubleConversion(static_cast<double>(value));
}

void ScalarConverter::convertFromDouble(double value)
{
	printCharConversion(value);
	printIntConversion(value);
	printFloatAndDoubleConversion(value);
}

void ScalarConverter::convert(std::string &literal)
{
	switch (identifyType(literal))
	{
		case CHAR:
			convertFromChar(literal[0]);
			break;
		case INT:
		{
			errno = 0;
			long int intValue = std::strtol(literal.c_str(), NULL, 10);
			
			if (errno == ERANGE || intValue > std::numeric_limits<int>::max() || intValue < std::numeric_limits<int>::min())
			{
				std::cout << "char: Non displayable" << std::endl;
				std::cout << "int: impossible" << std::endl;
				printFloatAndDoubleConversion(std::strtod(literal.c_str(), NULL));
			}
			else
				convertFromInt(static_cast<int>(intValue));
			break;
		}
		case FLOAT:
			convertFromFloat(std::strtof(literal.c_str(), NULL));
			break;
		case DOUBLE:
			convertFromDouble(std::strtod(literal.c_str(), NULL));
			break;
		default:
			std::cerr << "Invalid literal!" << std::endl;
			break;
	}
}
