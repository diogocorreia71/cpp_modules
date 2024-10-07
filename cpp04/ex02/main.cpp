/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:00:44 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/07 14:20:46 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const int numAnimals = 4;
	Animal* animals[numAnimals];
	
	for (int i = 0; i < numAnimals / 2; i++)
		animals[i] = new Dog();

	for (int i = numAnimals / 2; i < numAnimals; i++)
		animals[i] = new Cat();

	for (int i = 0; i < numAnimals; i++)
		animals[i]->makeSound();

	for (int i = 0; i < numAnimals; i++)
		delete animals[i];
	
    return 0;
}
