#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &src);
    void attack(const std::string& target);
    void highFivesGuys();
    unsigned int getAttackDamage() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    std::string getName() const;
};

std::ostream &operator<<(std::ostream &out, FragTrap &src);