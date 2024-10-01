/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:18:54 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/01 11:09:23 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::Fixed(const int nbr)
{
	this->_value = nbr * (1 << Fixed::bits);
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatnbr)
{
	this->_value = roundf(floatnbr * (1 << Fixed::bits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return _value;	
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_value / (float)(1 << Fixed::bits));
}

int Fixed::toInt( void ) const
{
	return (this->_value / (1 << Fixed::bits));
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->_value > other._value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->_value < other._value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->_value >= other._value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->_value <= other._value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->_value == other._value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->_value != other._value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	++_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++_value;
	return temp;
}

Fixed& Fixed::operator--()
{
	--_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--_value;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return out;
}
