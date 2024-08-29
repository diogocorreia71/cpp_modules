#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has been created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl has been distroyed" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love to get extra becon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			(this->*ptr_complain[i])();
			break;
		}
	}
}
