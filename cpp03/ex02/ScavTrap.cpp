#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) 
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << this->getName() << " has activated.\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap with the name of " << getName() << " has activated.\n";
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->getName() << " has turned off.\n";
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap " << this->getName() << " has been cloned!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if(this != &other) {}
    return *this;
};

void ScavTrap::attack(const std::string& target)
{
    if(!this->getEnergyPoints())
        return noEnergyAnnounce(this->getName());
    if(!this->getHitPoints())
        return noHitPointsAnnounce(this->getName());
    std::cout << "ScavTrap " 
        << this->getName() << " attacks " 
        << target << ", causing "
        << this->getAttackDamage() <<" points of damage!\n";
    setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::guardGate(void)
{
    std::cout << getName() << " is now in Gate keeper mode.\n";
}