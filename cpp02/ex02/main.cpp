/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:31 by diodos-s          #+#    #+#             */
/*   Updated: 2024/12/13 10:22:41 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// int main( void ) {
	
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
	
// 	return 0;
// }

int main() {
    // Test Default Constructor
    Fixed a;
    std::cout << "Default constructor test (a): " << a << std::endl;
    
    // Test Int Constructor
    Fixed b(10);
    std::cout << "Int constructor test (b = 10): " << b << std::endl;
    
    // Test Float Constructor
    Fixed c(10.5f);
    std::cout << "Float constructor test (c = 10.5f): " << c << std::endl;
    
    // Test Copy Constructor
    Fixed d(c);
    std::cout << "Copy constructor test (d = c): " << d << std::endl;
    
    // Test Copy Assignment Operator
    a = b;
    std::cout << "Copy assignment operator test (a = b): " << a << std::endl;
    
    // Test Arithmetic Operators
    Fixed e = b + c;
    std::cout << "Addition test (b + c): " << e << std::endl;
    
    Fixed f = b - c;
    std::cout << "Subtraction test (b - c): " << f << std::endl;
    
    Fixed g = b * c;
    std::cout << "Multiplication test (b * c): " << g << std::endl;
    
    Fixed h = b / c;
    std::cout << "Division test (b / c): " << h << std::endl;
    
    // Test Comparison Operators
    std::cout << "Comparison test (b > c): " << (b > c) << std::endl;
    std::cout << "Comparison test (b < c): " << (b < c) << std::endl;
    std::cout << "Comparison test (b >= c): " << (b >= c) << std::endl;
    std::cout << "Comparison test (b <= c): " << (b <= c) << std::endl;
    std::cout << "Comparison test (b == c): " << (b == c) << std::endl;
    std::cout << "Comparison test (b != c): " << (b != c) << std::endl;
    
    // Test Pre-increment and Post-increment
    std::cout << "Pre-increment test (++b): " << ++b << std::endl;
    std::cout << "Post-increment test (b++): " << b++ << std::endl;
    std::cout << "Post-increment result: " << b << std::endl;
    
    // Test Pre-decrement and Post-decrement
    std::cout << "Pre-decrement test (--b): " << --b << std::endl;
    std::cout << "Post-decrement test (b--): " << b-- << std::endl;
    std::cout << "Post-decrement result: " << b << std::endl;
    
    // Test Min and Max
    Fixed x(5.5f);
    Fixed y(10.5f);
    std::cout << "Min test (min(x, y)): " << Fixed::min(x, y) << std::endl;
    std::cout << "Max test (max(x, y)): " << Fixed::max(x, y) << std::endl;
    
    // Test const Min and Max
    const Fixed z(15.5f);
    std::cout << "Const Min test (min(const x, const z)): " << Fixed::min(x, z) << std::endl;
    std::cout << "Const Max test (max(const x, const z)): " << Fixed::max(x, z) << std::endl;
    
    return 0;
}