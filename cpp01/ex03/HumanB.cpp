#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL)
{
	this->_name = name;
	std::cout << "HumanB " << name << " created with no weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
