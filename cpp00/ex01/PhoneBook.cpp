/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:40:11 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/04 11:00:00 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

PhoneBook::PhoneBook() : id(0) {}

void PhoneBook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name: " << std::endl;
	getline(std::cin, first_name);
	if (first_name.empty())
	{
		std::cout << "Please enter a valid name." << std::endl;
		return;
	}
	std::cout << "Last name: " << std::endl;
	getline(std::cin, last_name);
	if (last_name.empty())
	{
		std::cout << "Please enter a valid last name." << std::endl;
		return;
	}
	std::cout << "Nickname: " << std::endl;
	getline(std::cin, nick_name);
	if (nick_name.empty())
	{
		std::cout << "Please enter a valid nickname." << std::endl;
		return;
	}
	std::cout << "Phone number: " << std::endl;
	getline(std::cin, phone_number);
	if (phone_number.empty())
	{
		std::cout << "Please enter a valid phone number." << std::endl;
		return;
	}
	std::cout << "Darkest secret: " << std::endl;
	getline(std::cin, darkest_secret);
	if (darkest_secret.empty())
	{
		std::cout << "Please enter a valid secret." << std::endl;
		return;
	}
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
