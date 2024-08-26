#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact 
{
	public:
		// Constructor
		Contact();
		Contact(std::string first_name,
				std::string last_name,
				std::string nick_name,
				std::string phone_number,
				std::string darkest_secret);
		std::string get_firstname();
		std::string get_lastname();
		std::string get_nickname();
		std::string get_phonenbr();
		std::string get_secret();

		// Destructor
		~Contact();

	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenbr;
		std::string secret;
};

#endif