#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_atack = 20;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_energy = other._energy;
	this->_atack = other._atack;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atack << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " was attacked " << amount << " times" << std::endl;
	this->_hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " healed himself " << amount << " times" << std::endl;
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
	return this->_atack;
}
