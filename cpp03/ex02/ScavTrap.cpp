#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name 
    << " constructed." <<  std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name 
    << " constructed." <<  std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name 
    << " destructed." <<  std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0 || this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name 
        << " has no energy or hit points left to attack." << std::endl;
        return ;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name 
    << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name 
    << " is now in Gate Keeper mode." << std::endl;
}

std::ostream &operator<<(std::ostream &out, ScavTrap &src)
{
	out << "ScavTrap " << src.getName()
	<< " [HP: " << src.getHitPoints()
	<< ", EP: " << src.getEnergyPoints()
	<< ", AD: " << src.getAttackDamage() << "]";
	return (out);
}

unsigned int ScavTrap::getAttackDamage() const
{
    return this->attackDamage;
}

unsigned int ScavTrap::getHitPoints() const
{
    return this->hitPoints;
}

unsigned int ScavTrap::getEnergyPoints() const
{
    return this->energyPoints;
}

std::string ScavTrap::getName() const
{
    return this->name;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    return (*this);
}