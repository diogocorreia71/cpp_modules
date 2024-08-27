#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << name << " created with ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}