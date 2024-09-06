/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:40:20 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/04 10:59:52 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdio.h>

int main()
{
	std::string option;
	PhoneBook phonebook;

	while (!std::cin.eof())
	{
		std::cout << "\033c";
		std::cout << "Please insert a command:" << std::endl;
		std::cout << "ADD" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "EXIT" << std::endl;

		std::cout << "Type a command: " << std::endl;
		getline(std::cin, option);

		if (option == "ADD")
			phonebook.add();
		else if (option == "SEARCH")
			phonebook.search();
		else if (option == "EXIT")
		{
			std::cout << "\033c";
			break;
		}
	}
}
