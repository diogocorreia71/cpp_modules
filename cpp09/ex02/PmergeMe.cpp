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

void PmergeMe::PmergeMeVector::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc ; i++)
	{
		this->vec.push_back(std::atoi(argv[i]));
		// if (this->vec.back() < 0)
		// 	throw PmergeMe::exception();
	}
}

void PmergeMe::PmergeMeVector::createVectorPairs()
{
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		this->vecPair.emplace_back(vec[i], vec[i + 1]);
	}
}

void PmergeMe::PmergeMeVector::sortVectorPairs()
{
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		if (vecPair.at(i).first < vecPair.at(i).second)
		{
			std::swap(vecPair.at(i).first, vecPair.at(i).second);
		}
	}
}

void PmergeMe::PmergeMeVector::merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end)
{
	size_t leftArrayIndex = 0;
	size_t rightArrayIndex = 0;
	size_t mergedArrayIndex = begin;

	std::vector<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + mid + 1);
	std::vector<std::pair<int, int> > rightArray(array.begin() + mid + 1, array.begin() + end + 1);

	while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
	{
		if (leftArray[leftArrayIndex].first <= rightArray[rightArrayIndex].first)
		{
			array[mergedArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
		}
		else
		{
			array[mergedArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
		}
		mergedArrayIndex++;
	}
	while (leftArrayIndex < leftArray.size())
	{
		array[mergedArrayIndex] = leftArray[leftArrayIndex];
		leftArrayIndex++;
		mergedArrayIndex++;
	}
	while (rightArrayIndex < rightArray.size())
	{
		array[mergedArrayIndex] = rightArray[rightArrayIndex];
		rightArrayIndex++;
		mergedArrayIndex++;
	}
}

void PmergeMe::PmergeMeVector::mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end)
{
	int mid;

	if (mid >= end)
		return;
	mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}