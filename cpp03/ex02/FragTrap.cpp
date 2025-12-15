#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name 
    << " constructed." <<  std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name 
    << " destructed." <<  std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0 || this->hitPoints == 0)
    {
        std::cout << "FragTrap " << this->name 
        << " has no energy or hit points left to attack." << std::endl;
        return ;
    }
    this->energyPoints--;
    std::cout << "FragTrap " << this->name 
    << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name 
    << " is requesting a high five! :D" << std::endl;
}

std::ostream &operator<<(std::ostream &out, FragTrap &src)
{
    out << "FragTrap " << src.getName()
    << " [HP: " << src.getHitPoints()
    << ", EP: " << src.getEnergyPoints()
    << ", AD: " << src.getAttackDamage() << "]";
    return (out);
}

unsigned int FragTrap::getAttackDamage() const
{
    return this->attackDamage;
}

unsigned int FragTrap::getHitPoints() const
{
    return this->hitPoints;
}

unsigned int FragTrap::getEnergyPoints() const
{
    return this->energyPoints;
}

std::string FragTrap::getName() const
{
    return this->name;
}