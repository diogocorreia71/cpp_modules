/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:36:36 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/07 11:43:45 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		virtual ~Dog();

		void makeSound() const;
		Brain *getBrain() const;
};

#endif