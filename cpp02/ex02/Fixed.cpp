#include "Fixed.hpp"

Fixed::Fixed()
{
	n = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->n = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->n;
}

void Fixed::setRawBits(int const raw)
{
	this->n = raw;
}

Fixed::Fixed(const int other_int)
{
	std::cout << "Int constructor called" << std::endl;
	n = other_int * 1 << this->frac;
}

Fixed::Fixed(const float other_float)
{
	std::cout << "Float constructor called" << std::endl;
	n = roundf(other_float *(1 << this->frac));
}

float Fixed::toFloat(void) const
{
	return (float)(n) / (1 << this->frac);
}

int Fixed::toInt(void) const
{
	return n >> this->frac;
}

std::ostream &operator<<(std::ostream &str, const Fixed &fixed_nbr)
{
	str << fixed_nbr.toFloat();
	return str;
}
