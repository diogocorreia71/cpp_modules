/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:46 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/26 18:14:05 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& vec, int value, int left, int right)
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

void fordJohnsonRecursive(std::vector<int>& vec, int left, int right)
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
	for (int i = 0; i < smaller.size(); ++ i)
	{
		int position = binarySearch(sortedChain, smaller[i], 0, sortedChain.size());
		sortedChain.insert(sortedChain.begin() + position, smaller[i]);
	}

	// write the sorted result back into the original vector
	for (int i = 0; i < sortedChain.size(); ++i)
	{
		vec[left + i] = sortedChain[i];
	}
}

void fordJohnsonSort(std::vector<int>& vec)
{
	fordJohnsonRecursive(vec, 0, vec.size() - 1);
}

int main()
{
	std::vector<int> vec = {62, 32, 25, 92, 26, 15, 96, 2, 51, 89, 42, 12, 1};

	std::cout << "Original array: " << std::endl;
	for (int num : vec) 
		std::cout << num << " ";
	std::cout << std::endl;
	
	fordJohnsonSort(vec);

	std::cout << "Sorted array: " << std::endl;
	for (int num : vec)
		std::cout << num << " " ;
	std::cout << std::endl;

	return 0;
}