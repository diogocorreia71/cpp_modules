/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:32:01 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/02 14:42:55 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap P1("Player1");
	ClapTrap CT("CT");

	P1.attack("Player2");
	P1.takeDamage(2);
	std::cout << P1.getName() << " has " << P1.getHP() << "hp" << std::endl;
	P1.beRepaired(5);
	std::cout << P1.getName() << " now has " << P1.getHP() << "hp" << std::endl;

	CT.attack("Player2");
	CT.takeDamage(2);
	std::cout << CT.getName() << " has " << CT.getHP() << "hp" << std::endl;
	CT.beRepaired(5);
	std::cout << CT.getName() << " now has " << CT.getHP() << "hp" << std::endl;

	P1.highFivesGuys();

	return 0;
}