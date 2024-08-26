#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie randomZ(name);

	randomZ.announce();
}
