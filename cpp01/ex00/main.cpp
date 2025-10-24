#include "Zombie.hpp"

int main()
{
	Zombie* zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete zombie1;

	Zombie zombie2;
	randomChump("Zombie2");

	return 0;
}