/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:46 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/02 10:26:23 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            std::cout << "Not enough args" << std::endl;
            return 0;
        }
        PmergeMe sort;
        std::vector<int> vec;
        std::deque<int> deq;

        // Fill the containers
        vec = sort.fillVector(argc, argv);
        deq = sort.fillDeque(argc, argv);

        // Display the input
        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << std::endl;

        // Sort and time the vector
        std::clock_t start = std::clock();
        sort.fordJohnsonSort(vec);
        std::clock_t end = std::clock();
        double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Vector after: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << argc - 1
                  << " elements with std::vec: " << std::fixed << std::setprecision(3)
                  << duration << " us" << std::endl;

        // Sort and time the deque
        start = std::clock();
        sort.fordJohnsonSort(deq);
        end = std::clock();
        duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Deque after: ";
        for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << argc - 1
                  << " elements with std::deque: " << std::fixed << std::setprecision(3)
                  << duration << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}