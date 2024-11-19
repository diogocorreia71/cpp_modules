/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:48:50 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/19 09:30:44 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
  private:
	std::map<std::string, float> _database;

  public:
	BitcoinExchange();
	BitcoinExchange(std::string inFile);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void createDatabase();
	void readFile(std::string file);
	float findValue(std::string date);
	bool isValidDate(const std::string &date);
};

#endif /* BitcoinExchange_HPP */