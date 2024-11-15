/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:49:01 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/14 12:40:59 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string inFile)
{
	createDatabase();
	// readFile(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	std::cout << "BitcoinExchange assignment operator called" << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::createDatabase()
{
	std::ifstream dataFile("data.csv");
	std::string str;

	if (!dataFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	int i = 0;
	while (std::getline(dataFile, str))
	{
		// if (i++ == 0)
		// 	continue;
		std::string date = str.substr(0, str.find(','));
		std::string rate = str.substr(str.find(',') + 1);
		this->_database[date] = atof(rate.c_str());
	}
}