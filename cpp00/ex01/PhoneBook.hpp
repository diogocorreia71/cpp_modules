/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:40:13 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/05 10:59:39 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		Contact contacts[8];

	private:
		int id;
		bool is_valid_input(const std::string &input);
		bool is_valid_phone_number(const std::string &number);
		std::string checklength(std::string str);
};

#endif