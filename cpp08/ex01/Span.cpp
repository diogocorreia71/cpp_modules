/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:41:33 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/12 14:21:54 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _maxSize(n)
{
	std::cout << "Span unsigned int constructor called" << std::endl;
}

Span::Span(const Span &other)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	std::cout << "Span assignment operator called" << std::endl;
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Cannot add more numbers, Span is full");
	_numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to compute a span");
	
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::out_of_range("Not enough elements to compute a span");
		
	int minElement = *std::min_element(_numbers.begin(), _numbers.end());
	int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
	return maxElement - minElement;
}
