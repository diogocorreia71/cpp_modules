/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:10 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/13 17:59:07 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <ctime>
#include <exception>
#include <cstdlib>

class PmergeMe 
{
	private:
		std::vector<int> _vec;
		std::vector<int> _pos;
		std::vector<std::pair<int, int> > _vecPair;
		std::vector<int> _mainChain;
		std::vector<int> _secChain;
		std::vector<int> _jacobSeq;

		std::deque<int> _deq;
		std::deque<int> _posDeq;
		std::deque<std::pair<int, int> > _deqPair;
		std::deque<int> _mainChainDeq;
		std::deque<int> _secChainDeq;
		std::deque<int> _jacobSeqDeq;


		// Vector functions
		void fillVector(int argc, char **argv);
		void createVectorPairs();
		void sortVectorPairs();
		void merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end);
		void mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end);
		void createMainChainAndSec();
		int binarySearch(std::vector<int> array, int target, int begin, int end);
		void generateJacobSeq();
		int jacobsthal(int n);
		void generatePos();
		void insertToMainChain();

		// Deque functions
		void fillDeque(int argc, char **argv);
		void createDequePairs();
		void sortDequePairs();
		void mergeDeque(std::deque<std::pair<int, int> > &array, int begin, int mid, int end);
		void mergeSortDeque(std::deque<std::pair<int, int> > &array, int begin, int end);
		void createChainsDeque();
		int binarySearchDeque(std::deque<int> array, int target, int begin, int end);
		void generateJacobDeque();
		void generatePosDeque();
		void insertToMainChainDeq();
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		bool isNumeric(const char *str);
		void applyFordJohnsonSort(int argc, char **argv);
		void applyFordJohnsonDeq(int argc, char **argv);
		void printBefore(int argc, char **argv);
		void printAfter();
		void printDeque();
		
		class exception : public std::exception
		{
			const char *what() const throw();
		};
};

#endif /* PMERGEME_HPP */