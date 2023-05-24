#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << this->getName() << " has activated.\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap with the name of " << getName() << " has activated.\n";
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->getName() << " has turned off.\n";
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap " << this->getName() << " has been cloned!\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if(this != &other) {}
    return *this;
};

void FragTrap::highFivesGuys(void)
{
    std::cout << "Hey man, that's your mate "<< getName() << " give me a highfive 🤚\n";
}