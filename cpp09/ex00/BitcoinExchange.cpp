/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:49:01 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/18 16:33:11 by diodos-s         ###   ########.fr       */
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
	readFile(inFile);
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

	if (!dataFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string str;
	int i = 0;
	while (std::getline(dataFile, str))
	{
		if (i++ == 0)
			continue;
		std::string date = str.substr(0, str.find(','));
		std::string rate = str.substr(str.find(',') + 1);
		this->_database[date] = atof(rate.c_str());
	}
}

void BitcoinExchange::readFile(std::string file)
{
	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	int i = 0;
	while (std::getline(inputFile, line))
	{
		if (i++ == 0)
			continue;
		size_t delimiterPos = line.find(" | ");
		if (delimiterPos == std::string::npos)
		{
			std::cerr << "Error: invalid format in line: " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, delimiterPos);
		std::string valueStr = line.substr(delimiterPos + 3);

		if (!isValidDate(date))
		{
			std::cerr << "Error: invalid date in line: " << line << std::endl;
			continue;
		}
		
		char* endPtr;
		double value = std::strtod(valueStr.c_str(), &endPtr);
		if (*endPtr != '\0' || value <= 0 || value > 1000)
		{
			std::cerr << "Error: invalid value in line: " << line << std::endl;
			continue;
		}
		
		float rate;
		try
		{
			rate = findValue(date);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
			continue;
		}
		
		float result = rate * static_cast<float>(value);
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

float BitcoinExchange::findValue(std::string date)
{
	std::map<std::string, float>::iterator it = _database.find(date);
	if (it != _database.end())
		return it->second;
	
	// if the exact date doesn't exist, find the closest earlier date
	it = _database.lower_bound(date);

	if (it == _database.begin() && it->first > date)
		throw std::runtime_error("No available exchange rate for date: " + date);

	if (it == _database.end() || it->first > date)
		--it;
	
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	std::istringstream yearStream(date.substr(0, 4));
	std::istringstream monthStream(date.substr(5, 2));
	std::istringstream dayStream(date.substr(8, 2));
	
	if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
		return false;
	
	if (year < 1900 || year > 2099)
		return false;
	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Adjust february for leap years
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}