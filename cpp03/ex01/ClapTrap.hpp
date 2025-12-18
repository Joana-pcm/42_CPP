#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int getAttackDamage() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	std::string getName() const;
};

std::ostream &operator<<(std::ostream &out, ClapTrap &src);