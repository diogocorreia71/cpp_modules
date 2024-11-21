/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:46 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/21 15:34:28 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility>

std::vector<int> mergeInsertionSort(std::vector<int> vec)
{
	// create pairs
	std::vector<std::pair<int, int> > pairs;

	for (std::size_t i = 0; i < vec.size(); i += 2)
	{
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;
	}

	std::cout << std::endl;

	// determine larger element of the pair
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;
	}

	std::vector<int> largest;
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		largest.push_back(pairs[i].second);
	}
	largest = mergeInsertionSort(largest);

	return largest;
}

int main()
{
	std::vector<int> vec = {62, 32, 25, 92, 26, 15, 96, 2, 51, 89, 42, 12};
	mergeInsertionSort(vec);


	return 0;
}