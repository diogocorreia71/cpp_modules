/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:20:01 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/07 11:38:40 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
    {
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destuctor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
    std::cout << type << " goes BARK" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}
