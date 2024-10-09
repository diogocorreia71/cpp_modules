/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:31:06 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/09 14:00:00 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
	public:
		Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif