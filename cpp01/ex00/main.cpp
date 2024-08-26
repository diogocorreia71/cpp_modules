#include "Zombie.hpp"

Zombie *newZombie(std::string name);

void randomChump(std::string name);

int main()
{
	Zombie *myZ;

	myZ = newZombie("Zacarias");
	myZ->announce();
	randomChump("Ezequiel");
	delete(myZ);
}
