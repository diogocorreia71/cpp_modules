/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:55 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/02 10:41:55 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	// std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_deque = other._deque;
	}
	// std::cout << "PmergeMe assignment operator called" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "PmergeMe destructor called" << std::endl;
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

int PmergeMe::binarySearch(const std::deque<int>& deq, int value, int left, int right)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (deq[mid] < value)
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

void PmergeMe::fordJohnsonRecursive(std::deque<int>& deq, int left, int right)
{
    int size = right - left + 1;
    if (size <= 1)
        return;

    // if size 2 direct swap
    if (size == 2)
    {
        if (deq[left] > deq[right])
        {
            std::swap(deq[left], deq[right]);
        }
        return;
    }

    // divide into pairs
    int mid = left + (size / 2);
    std::deque<int> smaller, larger;

    for (int i = left; i < mid; ++i)
    {
        if (deq[i] > deq[i + mid - left])
        {
            larger.push_back(deq[i]);
            smaller.push_back(deq[i + mid - left]);
        }
        else
        {
            larger.push_back(deq[i + mid - left]);
            smaller.push_back(deq[i]);
        }
    }

    // handle odd size
    if (size % 2 == 1)
        smaller.push_back(deq[right]);

    fordJohnsonRecursive(larger, 0, larger.size() - 1);

    // insert smaller elements into the larger group
    std::deque<int> sortedChain = larger;
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        int position = binarySearch(sortedChain, smaller[i], 0, sortedChain.size());
        sortedChain.insert(sortedChain.begin() + position, smaller[i]);
    }

    // write the sorted result back into the original deque
    for (size_t i = 0; i < sortedChain.size(); ++i)
    {
        deq[left + i] = sortedChain[i];
    }
}

void PmergeMe::fordJohnsonSort(std::deque<int>& deq)
{
    fordJohnsonRecursive(deq, 0, deq.size() - 1);
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

std::deque<int> PmergeMe::fillDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        this->_deque.push_back(std::atoi(argv[i]));
        if (this->_deque.back() < 0)
            throw Errors();
    }
    return this->_deque;
}

const char *PmergeMe::Errors::what() const throw()
{
	return "No negative numbers allowed";
}