#include "ClapTrap.hpp"

int main()
{
	ClapTrap P1("Player1");

	P1.attack("Player2");
	P1.takeDamage(2);
	std::cout << P1.getName() << " has " << P1.getHP() << "hp" << std::endl;
	P1.beRepaired(5);
	std::cout << P1.getName() << " now has " << P1.getHP() << "hp" << std::endl;
}