#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		Contact contacts[8];
		void add();
		void search();
		void exit();

	private:
		int id;
		std::string checklength(std::string str);
};

#endif