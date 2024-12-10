/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:45:16 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/10 10:01:55 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <cstdlib>

class RPN
{
  private:
	std::stack<long> _stack;

  public:
	RPN();
	RPN(const std::string &expression);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void calculate(std::string str);
};

#endif /* RPN_HPP */