/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:10 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/27 13:36:33 by diodos-s         ###   ########.fr       */
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

	int binarySearch(const std::vector<int>& vec, int value, int left, int right);
	void fordJohnsonRecursive(std::vector<int>& vec, int left, int right);
	void fordJohnsonSort(std::vector<int>& vec);
	std::vector<int> fillVector(int argc, char **argv);
	std::list<int> fillList(int argc, char **argv);

	class Errors : public std::exception
	{
		const char *what() const throw();
	};
};

#endif /* PMERGEME_HPP */