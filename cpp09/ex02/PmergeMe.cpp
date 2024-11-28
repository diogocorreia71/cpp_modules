/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:55 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/28 11:11:09 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_list = other._list;
	}
	std::cout << "PmergeMe assignment operator called" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

int PmergeMe::binarySearch(const std::vector<int>& vec, int value, int left, int right)
{
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (vec[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

void PmergeMe::fordJohnsonRecursive(std::vector<int>& vec, int left, int right)
{
	int size = right - left + 1;
	if (size <= 1)
		return;

	// if size 2 direct swap
	if (size == 2)
	{
		if (vec[left] > vec[right])
		{
			std::swap(vec[left], vec[right]);
		}
		return;
	}

	// divide into pairs
	int mid = left + (size / 2);
	std::vector<int> smaller, larger;

	for (int i = left; i < mid; ++i)
	{
		if (vec[i] > vec[i + mid - left])
		{
			larger.push_back(vec[i]);
			smaller.push_back(vec[i + mid - left]);
		}
		else
		{
			larger.push_back(vec[i + mid - left]);
			smaller.push_back(vec[i]);
		}
	}
	// handle odd size
	if (size % 2 == 1)
		smaller.push_back(vec[right]);

	fordJohnsonRecursive(larger, 0, larger.size() - 1);

	// insert smaller elements into the larger group
	std::vector<int> sortedChain = larger;
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		int position = binarySearch(sortedChain, smaller[i], 0, sortedChain.size());
		sortedChain.insert(sortedChain.begin() + position, smaller[i]);
	}

	// write the sorted result back into the original vector
	for (size_t i = 0; i < sortedChain.size(); ++i)
	{
		vec[left + i] = sortedChain[i];
	}
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec)
{
	fordJohnsonRecursive(vec, 0, vec.size() - 1);
}

std::list<int>::iterator PmergeMe::binarySearch(int value, std::list<int>::iterator left, std::list<int>::iterator right)
{
	while (left != right)
	{
		std::list<int>::iterator mid = left;
		std::advance(mid, std::distance(left, right) / 2);

		if (*mid < value)
			left = ++mid;
		else
			right = mid;
	}
	return left;
}

void PmergeMe::fordJohnsonRecursive(std::list<int>::iterator left, std::list<int>::iterator right)
{
	int size = std::distance(left, right);
	if (size <= 1)
		return;

	if (size == 2)
	{
		std::list<int>::iterator next = left;
		std::advance(next, 1);
		if (*left > *next)
			std::iter_swap(left, next);
		return;
	}

	std::list<int> smaller, larger;
	std::list<int>::iterator mid = left;
	std::advance(mid, size / 2);
	std::list<int>::iterator iter1 = left, iter2 = mid;

	while (iter1 != mid && iter2 != right)
	{
		if (*iter1 > *iter2)
		{
			larger.push_back(*iter1);
			smaller.push_back(*iter2);
		}
		else
		{
			larger.push_back(*iter2);
			smaller.push_back(*iter1);
		}
		++iter1;
		++iter2;
	}

	if (std::distance(mid, right) % 2 == 1)
		smaller.push_back(*iter2);

	std::list<int>::iterator larger_begin = larger.begin();
	std::list<int>::iterator larger_end = larger.end();
	fordJohnsonRecursive(larger_begin, larger_end);

	std::list<int> sortedChain(larger.begin(), larger.end());
	for (std::list<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
	{
		std::list<int>::iterator position = binarySearch(*it, sortedChain.begin(), sortedChain.end());
		sortedChain.insert(position, *it);
	}

	std::list<int>::iterator sorted_iter = sortedChain.begin();
	for (std::list<int>::iterator it = left; it != right; ++it, ++sorted_iter)
	{
		*it = *sorted_iter;
	}
}

void PmergeMe::fordJohnsonSort(std::list<int>& lst)
{
	fordJohnsonRecursive(lst.begin(), lst.end());
}

std::vector<int> PmergeMe::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		this->_vec.push_back(std::atoi(argv[i]));
		if (this->_vec.back() < 0)
			throw Errors();
	}
	return this->_vec;
}

std::list<int> PmergeMe::fillList(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		this->_list.push_back(std::atoi(argv[i]));
		if (this->_list.back() < 0)
			throw Errors();
	}
	return this->_list;
}

const char *PmergeMe::Errors::what() const throw()
{
	return "No negative numbers allowed";
}