/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:17:02 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/09 11:04:47 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int size;

	size = 20;
	Zombie *horde = zombieHorde(size, "Bandido");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete[] horde;
}
