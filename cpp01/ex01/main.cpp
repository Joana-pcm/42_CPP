#include "Zombie.hpp"

int main()
{
	Zombie* zombiegang = zombieHorde(8, "Zomzom");
	for (int i = 0; i < 8; i++)
		zombiegang[i].announce();
	
	delete [] zombiegang;
	return 0;
}