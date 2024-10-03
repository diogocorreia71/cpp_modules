/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:10:27 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/03 11:03:44 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
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
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_attack = other._attack;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy <= 0 || this->_hp <= 0) 
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack due to insufficient energy or HP" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energy--;	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " was attacked, taking " << amount << " HP of damage" << std::endl;
	this->_hp -= amount;
	if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " has no HP left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " healed himself " << amount << " HP" << std::endl;
	this->_hp += amount;
	this->_energy--;
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
