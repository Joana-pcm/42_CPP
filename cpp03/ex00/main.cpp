#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("ClapOne");
	ClapTrap clap2("ClapTwo");

	clap1.attack("ClapTwo");
	clap2.takeDamage(0);
	clap2.beRepaired(5);
	clap2.attack("ClapOne");
	clap1.takeDamage(0);
	clap1.beRepaired(3);

	return 0;
}