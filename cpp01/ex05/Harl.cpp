#include "Harl.hpp"

Harl::Harl () {};

Harl::~Harl() {};

void Harl::debug() 
{
	std::cout << "debugging..."
	<< std::endl;
}

void Harl::info() 
{
	std::cout << "I got some info for you." 
	<< std::endl;
}

void Harl::warning() 
{
	std::cout << "This is a warning!" 
	<< std::endl;
}

void Harl::error() 
{
	std::cout << "This is an error!" 
	<< std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (size_t i = 0; i < 4; i++) 
	{
		if (level == levels[i]) 
		{
			(this->*functions[i])();
			return ;
		}
	}
}