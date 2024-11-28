/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:10 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/28 11:02:33 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <iterator>

class PmergeMe 
{
  private:
	std::vector<int> _vec;
	std::list<int> _list;

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
	std::list<int>::iterator binarySearch(int value, std::list<int>::iterator left, std::list<int>::iterator right);
	void fordJohnsonRecursive(std::list<int>::iterator left, std::list<int>::iterator right);
	void fordJohnsonSort(std::list<int>& lst);
	
	std::vector<int> fillVector(int argc, char **argv);
	std::list<int> fillList(int argc, char **argv);

	class Errors : public std::exception
	{
		const char *what() const throw();
	};
};

#endif /* PMERGEME_HPP */