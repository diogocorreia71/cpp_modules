/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:40:11 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/05 11:05:25 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : id(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::is_valid_input(const std::string &input)
{
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!std::isspace(input[i]))
			return true;
	}
	return false;
}

bool PhoneBook::is_valid_phone_number(const std::string &number)
{
	if (number.empty())
		return false;
	for (size_t i = 0; i < number.length(); ++i)
	{
		if (!std::isdigit(number[i]))
			return false;
		if (number.length() != 9)
			return false;
	}
	return true;
}

void PhoneBook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	do
	{
		std::cout << "First name: " << std::endl;
		getline(std::cin, first_name);
		if (!is_valid_input(first_name))
			std::cout << "Please enter a valid name." << std::endl;
	} while (!is_valid_input(first_name));
	
	do
	{
		std::cout << "Last name: " << std::endl;
		getline(std::cin, last_name);
		if (!is_valid_input(last_name))
			std::cout << "Please enter a valid last name." << std::endl;
	} while (!is_valid_input(last_name));
	
	do
	{
		std::cout << "Nickname: " << std::endl;
		getline(std::cin, nick_name);
		if (!is_valid_input(nick_name))
			std::cout << "Please enter a valid nickname." << std::endl;
	} while (!is_valid_input(nick_name));
	
	do
	{
		std::cout << "Phone number: " << std::endl;
		getline(std::cin, phone_number);
		if (!is_valid_phone_number(phone_number))
			std::cout << "Please enter a valid phone number." << std::endl;
	} while (!is_valid_phone_number(phone_number));

	do
	{
		std::cout << "Darkest secret: " << std::endl;
		getline(std::cin, darkest_secret);
		if (!is_valid_input(darkest_secret))
			std::cout << "Please enter a valid secret." << std::endl;
	} while (!is_valid_input(darkest_secret));
	
	contacts[id++ % 8] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
}

std::string PhoneBook::checklength(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

void PhoneBook::search()
{
	PhoneBook phonebook;
	std::string index;
	int nbr;

	std::cout << "\033c";
	std::cout << "|   Index  |First Name|Last  Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << checklength(contacts[i].get_firstname()) << "|";
		std::cout << std::setw(10) << checklength(contacts[i].get_lastname()) << "|";
		std::cout << std::setw(10) << checklength(contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "Choose an index to display" << std::endl;
	std::cout << "Command BACK to return" << std::endl;
	while (1)
	{
		getline(std::cin, index);

		nbr = atoi(index.c_str());
		if (index == "BACK")
			break;
		else if (nbr > 8 || nbr < 1)
			std::cout << "Index out of range. Please try again" << std::endl;
		else if (nbr > id)
			std::cout << "Nothing to display for this index" << std::endl;
		else if (nbr <= id)
		{
			std::cout << "\033c";
			std::cout << "First name: " << contacts[nbr - 1].get_firstname() << std::endl;
			std::cout << "Last name: " << contacts[nbr - 1].get_lastname() << std::endl;
			std::cout << "Nickname: " << contacts[nbr - 1].get_nickname() << std::endl;
			std::cout << "Phone number: " << contacts[nbr - 1].get_phonenbr() << std::endl;
			std::cout << "Darkest secret: " << contacts[nbr - 1].get_secret() << std::endl;

			std::cout << "Press ENTER to continue..." << std::endl;
			getline(std::cin, index);
			break;
		}
	}
}
