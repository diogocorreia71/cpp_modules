/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:55 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/13 16:02:11 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::exception::what() const throw()
{
	return "Error";
}

// VECTOR FUNCTIONS

void PmergeMe::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc ; i++)
	{
		this->_vec.push_back(std::atoi(argv[i]));
		if (this->_vec.back() < 0)
			throw exception();
	}
}

void PmergeMe::createVectorPairs()
{
	for (size_t i = 0; i + 1 < this->_vec.size(); i += 2)
	{
		this->_vecPair.push_back(std::make_pair(this->_vec[i], this->_vec[i + 1]));
	}
}

void PmergeMe::sortVectorPairs()
{
	for (size_t i = 0; i < this->_vecPair.size(); i++)
	{
		if (this->_vecPair.at(i).first < this->_vecPair.at(i).second)
		{
			std::swap(this->_vecPair.at(i).first, this->_vecPair.at(i).second);
		}
	}
}

void PmergeMe::merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end)
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

void PmergeMe::mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	this->mergeSort(array, begin, mid);
	this->mergeSort(array, mid + 1, end);
	this->merge(array, begin, mid, end);
}

void PmergeMe::createMainChainAndSec()
{
	_mainChain.push_back(this->_vecPair.at(0).second);

	for (size_t i = 0; i < this->_vecPair.size(); i++)
	{
		_mainChain.push_back(this->_vecPair.at(i).first);
		_secChain.push_back(this->_vecPair.at(i).second);
	}
}

int PmergeMe::binarySearch(std::vector<int> array, int target, int begin, int end)
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

void PmergeMe::generateJacobSeq()
{
	size_t size = _secChain.size();
	size_t jacobIndex;
	int index = 3;

	while ((jacobIndex = this->jacobsthal(index)) < size - 1)
	{
		this->_jacobSeq.push_back(jacobIndex);
		index++;
	}
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::generatePos()
{
	size_t val;
	size_t position;
	size_t lastPos;

	if (this->_secChain.empty())
		return;
	this->generateJacobSeq();
	lastPos = 1;
	val = 1;
	
	for (size_t i = 0; i < this->_jacobSeq.size(); i++)
	{
		val = this->_jacobSeq.at(i);
		this->_pos.push_back(val);
		position = val - 1;
		while (position > lastPos)
		{
			this->_pos.push_back(position);
			position--;
		}
		lastPos = val;
	}
	while (val++ < this->_secChain.size())
		this->_pos.push_back(val);
}

void PmergeMe::insertToMainChain()
{
	std::vector<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t position;

	this->generatePos();
	addedCount = 0;

	for (it = this->_pos.begin(); it < this->_pos.end(); it++)
	{
		target = this->_secChain.at(*it - 1);
		endPos = *it + addedCount;
		position = this->binarySearch(this->_mainChain, target, 0, endPos);
		this->_mainChain.insert(this->_mainChain.begin() + position, target);
		addedCount++;
	}
	if (this->_vec.size() % 2 != 0)
	{
		target = this->_vec.at(this->_vec.size() - 1);
		position = this->binarySearch(this->_mainChain, target, 0, this->_mainChain.size() - 1);
		this->_mainChain.insert(this->_mainChain.begin() + position, target);
	}
}

// DEQUE FUNCTIONS

void PmergeMe::fillDeque(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		this->_deq.push_back(std::atoi(argv[i]));
		if (this->_deq.back() < 0)
			throw exception();
	}
}

void PmergeMe::createDequePairs()
{
	for (size_t i = 0; i + 1 < this->_deq.size(); i += 2)
	{
		this->_deqPair.push_back(std::make_pair(this->_deq[i], this->_deq[i + 1]));
	}
}

void PmergeMe::sortDequePairs()
{
	for (size_t i = 0; i < _deqPair.size(); i++)
	{
		if (this->_deqPair.at(i).first < this->_deqPair.at(i).second)
		{
			std::swap(this->_deqPair.at(i).first, this->_deqPair.at(i).second);
		}
	}
}

void PmergeMe::mergeDeque(std::deque<std::pair<int, int> > &array, int begin, int mid, int end)
{
	size_t leftArrayIndex = 0;
	size_t rightArrayIndex = 0;
	size_t mergedArrayIndex = begin;

	std::deque<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + mid + 1);
	std::deque<std::pair<int, int> > rightArray(array.begin() + mid + 1, array.begin() + end + 1);

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
		array[mergedArrayIndex] = rightArray[rightArrayIndex];
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

void PmergeMe::mergeSortDeque(std::deque<std::pair<int, int> > &array, int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	this->mergeSortDeque(array, begin, mid);
	this->mergeSortDeque(array, mid + 1, end);
	this->mergeDeque(array, begin, mid, end);
}

void PmergeMe::createChainsDeque()
{
	_mainChainDeq.push_back(this->_deqPair.at(0).second);

	for (size_t i = 0; i < this->_deqPair.size(); i++)
	{
		_mainChainDeq.push_back(this->_vecPair.at(i).first);
		_secChainDeq.push_back(this->_deqPair.at(i).second);
	}
}

int PmergeMe::binarySearchDeque(std::deque<int> array, int target, int begin, int end)
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

void PmergeMe::generateJacobDeque()
{
	size_t size = _secChainDeq.size();
	size_t jacobInd;
	int index = 3;

	while ((jacobInd = this->jacobsthal(index)) < size - 1)
	{
		this->_jacobSeqDeq.push_back(jacobInd);
		index++;
	}
}

void PmergeMe::generatePosDeque()
{
	size_t val;
	size_t position;
	size_t lastPos;

	if (this->_secChainDeq.empty())
		return;
	this->generateJacobDeque();
	lastPos = 1;
	val = 1;

	for (size_t i = 0; i < this->_jacobSeqDeq.size(); i++)
	{
		val = this->_jacobSeqDeq.at(i);
		this->_posDeq.push_back(val);
		position = val - 1;
		while (position > lastPos)
		{
			this->_posDeq.push_back(position);
			position--;
		}
		lastPos = val;
	}
	while (val++ < this->_secChainDeq.size())
		this->_posDeq.push_back(val);
}

void PmergeMe::insertToMainChainDeq()
{
	std::deque<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t position;

	this->generatePosDeque();
	addedCount = 0;

	for (it = this->_posDeq.begin(); it < this->_posDeq.end(); it++)
	{
		target = this->_secChainDeq.at(*it - 1);
		endPos = *it + addedCount;
		position = this->binarySearchDeque(this->_mainChainDeq, target, 0, endPos);
		this->_mainChainDeq.insert(this->_mainChainDeq.begin() + position, target);
		addedCount++;
	}
	if (this->_deq.size() % 2 != 0)
	{
		target = this->_deq.at(this->_deq.size() - 1);
		position = this->binarySearchDeque(this->_mainChainDeq, target, 0, this->_mainChainDeq.size() - 1);
		this->_mainChainDeq.insert(this->_mainChainDeq.begin() + position, target);
	}
}

void PmergeMe::applyFordJohnsonSort(int argc, char **argv)
{
	this->fillVector(argc, argv);

	if (this->_vec.size() == 1)
	{
		this->_mainChain.push_back(this->_vec.at(0));
	}
	else
	{
		this->createVectorPairs();
		this->sortVectorPairs();
		this->mergeSort(this->_vecPair, 0, this->_vecPair.size() - 1);
		this->createMainChainAndSec();
		this->insertToMainChain();
	}
}

void PmergeMe::applyFordJohnsonDeq(int argc, char **argv)
{
	this->fillDeque(argc, argv);
	
	if (this->_deq.size() == 1)
	{
		this->_mainChainDeq.push_back(this->_deq.at(0));
	}
	else
	{
		this->createDequePairs();
		this->sortDequePairs();
		this->mergeSortDeque(this->_deqPair, 0, this->_deqPair.size() - 1);
		this->createChainsDeque();
		this->insertToMainChainDeq();
	}
}

void PmergeMe::printBefore()
{
	for (unsigned int i = 0; i < this->_vec.size(); i++)
	{
		std::cout << this->_vec.at(i) << " ";
	}
}

void PmergeMe::printAfter()
{
	for (unsigned int i = 0; i < this->_mainChain.size(); i++)
	{
		std::cout << this->_mainChain.at(i) << " ";
	}
}