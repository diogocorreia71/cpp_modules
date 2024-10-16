/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:38:19 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/16 17:44:05 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	std::cout << "Testing char input:" << std::endl;
	ScalarConverter::convert("A");

	std::cout << "\nTesting int input:" << std::endl;
    ScalarConverter::convert("42");

    std::cout << "\nTesting float input:" << std::endl;
    ScalarConverter::convert("42.0f");

    std::cout << "\nTesting double input:" << std::endl;
    ScalarConverter::convert("42.0");

    std::cout << "\nTesting invalid input:" << std::endl;
    ScalarConverter::convert("HelloWorld");

    return 0;
}