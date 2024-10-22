/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:07:38 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/22 10:01:13 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <cerrno>

class ScalarConverter
{
	private:
		enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

		static Type identifyType(const std::string &literal);
		static void printCharConversion(double value);
		static void printIntConversion(double value);
		static void printFloatAndDoubleConversion(double value);
		static void convertFromChar(char value);
		static void convertFromInt(int value);
		static void convertFromFloat(float value);
		static void convertFromDouble(double value);
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		
	public:
		static void convert(std::string &literal);
};

#endif