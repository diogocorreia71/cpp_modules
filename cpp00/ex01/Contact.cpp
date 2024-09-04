/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:40:23 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/04 09:40:24 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	firstname = first_name;
	lastname = last_name;
	nickname = nick_name;
	phonenbr = phone_number;
	secret = darkest_secret;
}

// Destructor
Contact::~Contact()
{
}

// Methods
std::string Contact::get_firstname()
{
	return firstname;
}

std::string Contact::get_lastname()
{
	return lastname;
}

std::string Contact::get_nickname()
{
	return nickname;
}

std::string Contact::get_phonenbr()
{
	return phonenbr;
}

std::string Contact::get_secret()
{
	return secret;
}

