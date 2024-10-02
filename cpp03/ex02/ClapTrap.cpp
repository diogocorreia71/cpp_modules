/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:32:04 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/02 13:40:55 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_hp = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
	_hp = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_attack = other._attack;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_energy = other._energy;
		_attack = other._attack;	
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy <= 0 || this->_hp <= 0) 
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " was attacked " << amount << " times" << std::endl;
	this->_hp -= amount;
	if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " has no hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " healed himself " << amount << " times" << std::endl;
	this->_hp += amount;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHP() const
{
	return this->_hp;
}

int ClapTrap::getEnergy() const
{
	return this->_energy;
}

int ClapTrap::getAttack() const
{
	return this->_attack;
}
