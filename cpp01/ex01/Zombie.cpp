#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::Zombie(void){}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is destroyed!" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
	this->_name = name;
}
