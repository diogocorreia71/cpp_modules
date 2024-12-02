/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:10 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/02 10:41:21 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <iterator>
#include <iomanip>

class PmergeMe 
{
  private:
	std::vector<int> _vec;
	std::deque<int> _deque;

  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	// vector
	int binarySearch(const std::vector<int>& vec, int value, int left, int right);
	void fordJohnsonRecursive(std::vector<int>& vec, int left, int right);
	void fordJohnsonSort(std::vector<int>& vec);
	
	// list
	int binarySearch(const std::deque<int>& deq, int value, int left, int right);
	void fordJohnsonRecursive(std::deque<int>& deq, int left, int right);
	void fordJohnsonSort(std::deque<int>& deq);
	
	std::vector<int> fillVector(int argc, char **argv);
	std::deque<int> fillDeque(int argc, char **argv);

	class Errors : public std::exception
	{
		const char *what() const throw();
	};
};

#endif /* PMERGEME_HPP */