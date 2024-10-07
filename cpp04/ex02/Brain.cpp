/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:19:14 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/07 11:25:30 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        ideas[i] = "New idea";
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    delete[] ideas;
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "Invalid index";
}

void Brain::setIdea(int index, const std::string &newIdea)
{
    if (index >= 0 && index < 100)
        ideas[index] = newIdea;
}
