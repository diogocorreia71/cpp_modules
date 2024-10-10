/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:40:38 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/10 14:48:15 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "Form default consturctor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _grade_to_sign(signGrade), _grade_to_execute(execGrade)
{
	std::cout << "Form: " << _name << " constructor called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	this->_signed = false;
}

Form::Form(const Form &other) : _name(other._name), _signed(), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_signed = other._signed;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form()
{
	std::cout << _name << " destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getFormStatus() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_grade_to_sign;
}

int Form::getExecGrade() const
{
	return this->_grade_to_execute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << " because it's already been signed" << std::endl;
	else if (!this->_signed && bureaucrat.getGrade() <= this->_grade_to_sign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		this->_signed = true;	
	}
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
	out << other.getName() << " form";
	if (other.getFormStatus())
		out << " is signed" << std::endl;
	else
		out << " isn't signed" << std::endl;
	out << "Sign grade is " << other.getSignGrade() << std::endl;
	out << "Execution grade is " << other.getExecGrade() << std::endl;
	return out;
}
