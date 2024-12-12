/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:55 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/12 11:02:06 by diodos-s         ###   ########.fr       */
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

PmergeMe::exception::exception() {}

PmergeMe::exception::~exception() throw() {}

const char *PmergeMe::exception::what() const throw()
{
	return "Error";
}

void PmergeMe::PmergeMeVector::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc ; i++)
	{
		this->vec.push_back(std::atoi(argv[i]));
		if (this->vec.back() < 0)
			throw PmergeMe::exception();
	}
}

void PmergeMe::PmergeMeVector::createVectorPairs()
{
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		this->vecPair.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
}

void PmergeMe::PmergeMeVector::sortVectorPairs()
{
	for (size_t i = 0; i < this->vecPair.size(); i++)
	{
		if (this->vecPair.at(i).first < this->vecPair.at(i).second)
		{
			std::swap(this->vecPair.at(i).first, this->vecPair.at(i).second);
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

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	this->mergeSort(array, begin, mid);
	this->mergeSort(array, mid + 1, end);
	this->merge(array, begin, mid, end);
}

void PmergeMe::PmergeMeVector::createMainChainAndSec()
{
	mainChain.push_back(this->vecPair.at(0).second);

	for (size_t i = 0; i < this->vecPair.size(); i++)
	{
		mainChain.push_back(this->vecPair.at(i).first);
		secChain.push_back(this->vecPair.at(i).second);
	}
}

int PmergeMe::PmergeMeVector::binarySearch(std::vector<int> array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return mid;
		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return mid + 1;
	else
		return mid;
}

void PmergeMe::PmergeMeVector::generateJacobSeq()
{
	size_t size = secChain.size();
	size_t jacobIndex;
	int index = 3;

	while ((jacobIndex = this->jacobsthal(index)) < size - 1)
	{
		this->jacobSeq.push_back(jacobIndex);
		index++;
	}
}

int PmergeMe::PmergeMeVector::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::PmergeMeVector::generatePos()
{
	size_t val;
	size_t position;
	size_t lastPos;

	if (this->secChain.empty())
		return;
	this->generateJacobSeq();
	lastPos = 1;
	val = 1;
	
	for (size_t i = 0; i < this->jacobSeq.size(); i++)
	{
		val = this->jacobSeq.at(i);
		this->pos.push_back(val);
		position = val - 1;
		while (position > lastPos)
		{
			this->pos.push_back(position);
			position--;
		}
		lastPos = val;
	}
	while (val++ < this->secChain.size())
		this->pos.push_back(val);
}

void PmergeMe::PmergeMeVector::insertToMainChain()
{
	std::vector<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t position;

	this->generatePos();
	addedCount = 0;

	for (it = this->pos.begin(); it < this->pos.end(); it++)
	{
		target = this->secChain.at(*it - 1);
		endPos = *it + addedCount;
		position = this->binarySearch(this->mainChain, target, 0, endPos);
		this->mainChain.insert(this->mainChain.begin() + position, target);
		addedCount++;
	}
	if (this->vec.size() % 2 != 0)
	{
		target = this->vec.at(this->vec.size() - 1);
		position = this->binarySearch(this->mainChain, target, 0, this->mainChain.size() - 1);
		this->mainChain.insert(this->mainChain.begin() + position, target);
	}
}

PmergeMe::PmergeMeVector::PmergeMeVector() {}

PmergeMe::PmergeMeVector::~PmergeMeVector() {}

void PmergeMe::PmergeMeVector::applyFordJohnsonSort(int argc, char **argv)
{
	this->fillVector(argc, argv);

	if (this->vec.size() == 1)
	{
		this->mainChain.push_back(this->vec.at(0));
	}
	else
	{
		this->createVectorPairs();
		this->sortVectorPairs();
		this->mergeSort(this->vecPair, 0, this->vecPair.size() - 1);
		this->createMainChainAndSec();
		this->insertToMainChain();
	}
}

void PmergeMe::PmergeMeVector::printBefore()
{
	for (unsigned int i = 0; i < this->vec.size(); i++)
	{
		std::cout << this->vec.at(i) << " ";
	}
}

void PmergeMe::PmergeMeVector::printAfter()
{
	for (unsigned int i = 0; i < this->mainChain.size(); i++)
	{
		std::cout << this->mainChain.at(i) << " ";
	}
}