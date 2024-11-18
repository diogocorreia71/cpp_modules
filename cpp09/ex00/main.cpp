/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:48:28 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/18 15:35:33 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::ifstream testFile(argv[1]);
		if (!testFile.is_open())
		{
			std::cerr << "Error: could not open file: " << argv[1] << std::endl;
			return 1;
		}
		testFile.close();

		BitcoinExchange convert(argv[1]);
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	
	return 0;
}