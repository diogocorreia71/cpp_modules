/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:49:35 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/31 10:04:11 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(new T[0])
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]())
{
	std::cout << "Unsigned int constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size), _array(new T[other._size])
{
	std::cout << "Array copy constructor called" << std::endl;
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) 
{
	if (this != &other) 
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[other._size];
		for (unsigned int i = 0; i < _size; i++)
			this->_array[i] = other._array[i];
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
		throw OutOfBounds();
	return this->_array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return "Index out of bounds";
}
