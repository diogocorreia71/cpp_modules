/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:46 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/27 13:41:28 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Not enough args" << std::endl;
		return 0;
	}
	PmergeMe sort;
	std::vector<int> vec;
	std::list<int> list;
	vec = sort.fillVector(argc, argv);
	list = sort.fillList(argc, argv);

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::clock_t start = std::clock();
	sort.fordJohnsonSort(vec);
	std::cout << "Vector after: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::clock_t end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vec: " << duration << " us" << std::endl;
	

	return 0;
}