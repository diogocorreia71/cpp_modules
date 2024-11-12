/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:40:53 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/12 14:21:50 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iterator>

class Span 
{
  private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

  public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	
	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	
	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end)
	{
		size_t rangeSize = std::distance(begin, end);
		if (_numbers.size() + rangeSize > _maxSize)
			throw std::out_of_range("Adding this range exceeds Span capacity");
		
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif /* SPAN_HPP */