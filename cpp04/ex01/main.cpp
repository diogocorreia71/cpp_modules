/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:00:44 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/07 11:42:37 by diodos-s         ###   ########.fr       */
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
	

	// Dog dog1;
    // dog1.getBrain()->setIdea(0, "Dog's special idea"); 

    // std::cout << "Dog1's first idea: " << dog1.getBrain()->getIdea(0) << std::endl;

    // Dog dog2(dog1); 
    // std::cout << "Dog2's first idea (copied from Dog1): " << dog2.getBrain()->getIdea(0) << std::endl;

    // dog2.getBrain()->setIdea(0, "Dog2's own idea"); 

    // std::cout << "Dog1's first idea after modification to Dog2: " << dog1.getBrain()->getIdea(0) << std::endl;
    // std::cout << "Dog2's first idea after modification: " << dog2.getBrain()->getIdea(0) << std::endl;

	// Dog dog3;
	// dog3 = dog1;
	// std::cout << "Dog3's first idea (copied from Dog1): " << dog3.getBrain()->getIdea(0) << std::endl;

	// dog3.getBrain()->setIdea(0, "Dog3's own idea");
	
	// std::cout << "Dog1's first idea after modification to Dog3: " << dog1.getBrain()->getIdea(0) << std::endl;
	// std::cout << "Dog3's first idea after modification: " << dog3.getBrain()->getIdea(0) << std::endl;

    return 0;
}
