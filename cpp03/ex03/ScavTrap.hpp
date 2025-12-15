#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &src);
    void attack(const std::string& target);
    void guardGate();
    unsigned int getAttackDamage() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    std::string getName() const;
};

std::ostream &operator<<(std::ostream &out, ScavTrap &src);