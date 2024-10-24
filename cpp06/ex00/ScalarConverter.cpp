/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:51 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/24 11:38:34 by diodos-s         ###   ########.fr       */
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

    if (literal[literal.length() - 1] == 'f' && literal.find('.') != std::string::npos)
	{
		std::strtof(literal.c_str(), &end);
		if (*end == 'f' && *(end + 1) == '\0')
        	return FLOAT;
	}

    std::strtod(literal.c_str(), &end);
    if (*end == '\0')
        return DOUBLE;

    return INVALID;
}

void ScalarConverter::convert(std::string &literal)
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

void ScalarConverter::convertChar(const std::string &literal)
{
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string &literal)
{
    long value = std::strtol(literal.c_str(), NULL, 10);

    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
	{
        std::cout << "char: Non displayable" << std::endl;
	}
	
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	 	std::cout << "int: impossible" << std::endl;	
	else
    	std::cout << "int: " << value << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal)
{
    float value = std::strtof(literal.c_str(), NULL);

    if (std::isnan(value) || std::isinf(value)) 
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } 
	else 
	{
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<char>(value)))
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	 		std::cout << "int: impossible" << std::endl;	
		else
    		std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    double value = std::strtod(literal.c_str(), NULL);

    if (std::isnan(value) || std::isinf(value))
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
	else
	{
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<char>(value)))
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	 		std::cout << "int: impossible" << std::endl;	
		else
    		std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

