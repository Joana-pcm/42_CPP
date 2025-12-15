#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap &src);
    DiamondTrap &operator=(const DiamondTrap &src);
    void attack(const std::string& target);
    void whoAmI();
    unsigned int getAttackDamage() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    std::string getName() const;
};

std::ostream &operator<<(std::ostream &out, DiamondTrap &src);