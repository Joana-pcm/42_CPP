#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap1("ClapOne");
	ScavTrap scav1("ScavOne");
	FragTrap frag1("FragOne");

	for (int i = 0; i < 6; i++)
	{
		std::cout << "\n----------STATS----------" << std::endl;
		std::cout << clap1 << std::endl;
		std::cout << scav1 << std::endl;
		std::cout << frag1 << std::endl;
		std::cout << "\n--------ROUND " << i + 1 << "--------" << std::endl;
		clap1.attack("ScavOne");
		scav1.takeDamage(clap1.getAttackDamage());
		scav1.beRepaired(5);
		scav1.attack("ClapOne");
		clap1.takeDamage(scav1.getAttackDamage());
		clap1.beRepaired(5);
		frag1.attack("ClapOne");
		clap1.takeDamage(frag1.getAttackDamage());
		clap1.beRepaired(5);
		std::cout << "\n--------HIGH FIVE--------" << std::endl;
		frag1.highFivesGuys();
		std::cout << std::endl;
	}
	return 0;
}