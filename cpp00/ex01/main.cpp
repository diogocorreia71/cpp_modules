#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdio.h>

int main()
{
	std::string option;
	PhoneBook phonebook;

	while (1)
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
