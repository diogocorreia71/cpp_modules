/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:46 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/13 16:00:28 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    clock_t timeVec;
	clock_t timeDeq;

	PmergeMe pmVec;
	PmergeMe pmDeq;

	if (argc == 1)
	{
		std::cerr << "usage: " << argv[0] << " ...numbers" << std::endl;
		return 1;
	}

	try
	{
		timeVec = clock();
		pmVec.applyFordJohnsonSort(argc, argv);
		timeVec = clock() - timeVec;

		timeDeq = clock();
		pmDeq.applyFordJohnsonDeq(argc, argv);
		timeDeq = clock() - timeDeq;

		std::cout << "Before: ";
		pmVec.printBefore();
		std::cout << std::endl;

		std::cout << "After: ";
		pmVec.printAfter();
		std::cout << std::endl;

		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (float)timeVec * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << (float)timeDeq * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		

    return 0;
}