/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:18:54 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/30 14:23:59 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::Fixed(const int nbr)
{
	this->_value = nbr * (1 << Fixed::bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatnbr)
{
	this->_value = roundf(floatnbr * (1 << Fixed::bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return out;
}
