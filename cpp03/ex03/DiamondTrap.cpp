#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("Monster")
{
    this->hitPoints = FragTrap::getHitPoints();
    this->energyPoints = ScavTrap::getEnergyPoints();
    this->attackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap " << this->name 
    << " constructed." <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    this->hitPoints = FragTrap::getHitPoints();
    this->energyPoints = ScavTrap::getEnergyPoints();
    this->attackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap " << this->name 
    << " constructed." <<  std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name 
    << " destructed." <<  std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name 
    << ", ClapTrap name: " << ClapTrap::name << " o_O"<< std::endl;
}

std::ostream &operator<<(std::ostream &out, DiamondTrap &src)
{
    out << "DiamondTrap " << src.getName()
    << " [HP: " << src.getHitPoints()
    << ", EP: " << src.getEnergyPoints()
    << ", AD: " << src.getAttackDamage() << "]";
    return (out);
}

unsigned int DiamondTrap::getAttackDamage() const
{
    return this->attackDamage;
}

unsigned int DiamondTrap::getHitPoints() const
{
    return this->hitPoints;
}

unsigned int DiamondTrap::getEnergyPoints() const
{
    return this->energyPoints;
}

std::string DiamondTrap::getName() const
{
    return this->name;
}