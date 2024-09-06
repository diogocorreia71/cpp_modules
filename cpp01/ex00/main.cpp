/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:24:09 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:10 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *myZ;

	myZ = newZombie("Zacarias");
	myZ->announce();
	randomChump("Ezequiel");
	delete(myZ);
}
