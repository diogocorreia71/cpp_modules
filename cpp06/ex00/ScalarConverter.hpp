/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:07:38 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/16 17:42:23 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
	private:
		enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

		static Type identifyType(const std::string literal);
		static void convertChar(const std::string literal);
		static void convertInt(const std::string literal);
		static void convertFloat(const std::string literal);
		static void convertDouble(const std::string literal);
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		
	public:
		static void convert(std::string literal);
};

#endif