/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:10 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/10 17:42:55 by diodos-s         ###   ########.fr       */
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

class PmergeMe 
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		
		class PmergeMeVector
		{
			private:
				std::vector<int> vec;
				std::vector<int> pos;
				std::vector<std::pair<int, int> > vecPair;
				std::vector<int> mainChain;
				std::vector<int> secChain;
				std::vector<int> jacobSeq;

				std::vector<int> fillVector(int argc, char **argv);
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
				
			public:
				PmergeMeVector();
				~PmergeMeVector();
				void applyFordJohnsonSort(char **argv);
				void printBefore();
				void printAfter();
		};

};

#endif /* PMERGEME_HPP */