/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:45:16 by diodos-s          #+#    #+#             */
/*   Updated: 2024/11/20 10:15:08 by diodos-s         ###   ########.fr       */
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

class RPN
{
  private:
	std::stack<int> _stack;

  public:
	RPN();
	RPN(const std::string &expression);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void calculate(std::string str);
};

#endif /* RPN_HPP */