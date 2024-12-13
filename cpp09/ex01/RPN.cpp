/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:45:18 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/13 13:10:24 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const std::string &expression)
{
	calculate(expression);
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculate(std::string str)
{
	std::istringstream input(str);
	std::string token;

	while (input >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
        {
            long num;
            try
            {
                num = std::atol(token.c_str());
                if (num == 0 && token != "0")
                    throw std::runtime_error("Error: Invalid number in expression");
            }
            catch (const std::exception& e)
            {
                throw std::runtime_error("Error: Invalid number in expression");
            }
            _stack.push(num);
        }
		else if (token.size() == 1 && (token == "+" || token == "-" || token == "*" || token == "/"))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands for operation");
			long b = _stack.top();
			_stack.pop();
			long a = _stack.top();
			_stack.pop();
			long result = 0;

			if (token == "+")
			{
				if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
					throw std::runtime_error("Error: Overflow in addition");
				result = a + b;
			}
			else if (token == "-")
			{
				if ((b > 0 && a > INT_MAX + b) || (b < 0 && a < INT_MIN + b))
					throw std::runtime_error("Error: Overflow in subtraction");
				result = a - b;
			}
			else if (token == "*")
			{
				if (a != 0 && (b > INT_MAX / a || b < INT_MIN / a))
					throw std::runtime_error("Error: Overflow in multiplication");
				result = a * b;
			}
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				else if (a != 0 && (b > INT_MAX + a || b < INT_MIN + a))
					throw std::runtime_error("Error: Overflow in division");
				result = a / b;
			}

			_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Error: Invalid token in expression");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression");
	std::cout << "Result: " << _stack.top() << std::endl;
}
