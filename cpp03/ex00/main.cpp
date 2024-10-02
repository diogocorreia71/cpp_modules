/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:10:35 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/02 11:28:00 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap P1("Player1");

	P1.attack("Player2");
	P1.takeDamage(10);
	P1.attack("Player2");
	P1.beRepaired(5);
	std::cout << P1.getName() << " now has " << P1.getHP() << "hp" << std::endl;
	P1.attack("Player2");
}
