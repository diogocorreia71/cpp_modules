/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:10:44 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/30 16:28:25 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() 
{
	std::cout << "Array default constructor called" << std::endl;
	this->_array = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Unsigned int constructor called" << std::endl;
	this->_size = n;
	this->_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other) 
{
	std::cout << "Array copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) 
{
	if (this != &other) 
	{
		this->_size = other._size;
		this->_array = other._array;
	}
	std::cout << "Array assignment operator called" << std::endl;
	return *this;
}

template <typename T>
Array<T>::~Array() 
{
	std::cout << "Array destructor called" << std::endl;
	delete[] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw (std::range_error("Out of range"));
	return this->_array[i];
}