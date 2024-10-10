/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:40:38 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/10 14:48:15 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "AForm default consturctor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _grade_to_sign(signGrade), _grade_to_execute(execGrade)
{
	std::cout << "AForm: " << _name << " constructor called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	this->_signed = false;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	std::cout << "AForm copy constructor called" << std::endl;
	this->_signed = other._signed;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << _name << " destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getAFormStatus() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_grade_to_sign;
}

int AForm::getExecGrade() const
{
	return this->_grade_to_execute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << " because it's already been signed" << std::endl;
	else if (!this->_signed && bureaucrat.getGrade() <= this->_grade_to_sign)
	{
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		this->_signed = true;	
	}
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
	out << other.getName() << " Aform";
	if (other.getAFormStatus())
		out << " is signed" << std::endl;
	else
		out << " isn't signed" << std::endl;
	out << "Sign grade is " << other.getSignGrade() << std::endl;
	out << "Execution grade is " << other.getExecGrade() << std::endl;
	return out;
}
