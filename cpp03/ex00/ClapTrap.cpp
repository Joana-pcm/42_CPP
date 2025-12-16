#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Bob"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name 
	<< " constructed." <<  std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name 
	<< " constructed." <<  std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name 
	<< " destructed." <<  std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->name = src.name;
	this->attackDamage = src.attackDamage;
	this->energyPoints = src.energyPoints;
	this->hitPoints = src.hitPoints;
	std::cout << "Copy constructor called." << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
		(*this) = src;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name 
		<< " has no energy or hit points left to attack." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name 
	<< " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount 
	<< " points of damage! Remaining hit points: " << this->hitPoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name 
		<< " has no energy or hit points left to repair." << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name 
	<< " is repaired by " << amount << " points! New hit points: " << this->hitPoints << std::endl;
}

std::ostream &operator<<(std::ostream &out, ClapTrap &src)
{
	out << "ClapTrap " << src.getName() 
	<< " [HP: " << src.getHitPoints()
	<< ", EP: " << src.getEnergyPoints()
	<< ", AD: " << src.getAttackDamage() << "]";
	return (out);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

unsigned int ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

std::string ClapTrap::getName() const
{
	return this->name;
}