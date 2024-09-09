/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:19:25 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/09 12:19:26 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):_type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return(this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
