#include "Zombie.hpp"

Zombie::Zombie()
{
}
Zombie::Zombie(std::string name) : name(name)
{
	this->name = name;
}

Zombie::~Zombie()
{
}
void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnnzzzZ..." << std::endl;
}