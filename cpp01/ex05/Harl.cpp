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
	void (Harl::*func_ptr())
/* 	std::cout << level[0] << std::endl; */
	switch (level[0])
	{
		case 'D':
		debug();
		break ;
		case 'I':
		info();
		break ;
		case 'W':
		warning();
		break ;
		case 'E':
		error();
		break ;
	}
}