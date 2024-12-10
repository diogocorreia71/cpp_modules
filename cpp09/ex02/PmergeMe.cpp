/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:55 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/10 17:45:27 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	(void)other;
	// std::cout << "PmergeMe assignment operator called" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "PmergeMe destructor called" << std::endl;
}

std::vector<int> PmergeMe::PmergeMeVector::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc ; i++)
	{
		this->vec.push_back(std::atoi(argv[i]));
		// if (this->vec.back() < 0)
		// 	throw PmergeMe::exception();
	}
	return this->vec;
}

void PmergeMe::PmergeMeVector::createVectorPairs()
{
	
}