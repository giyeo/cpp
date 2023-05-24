#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
    ClapTrap::name = "rfa";

    std::cout << "DiamondTrap " << this->getName() << " has activated.\n";
}

DiamondTrap::DiamondTrap(const std::string name) : name(name)
{
    std::cout << "DiamondTrap with the name of " << this->getName() << " has activated.\n";
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->getName() << " has turned off.\n";
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap " << this->getName() << " has been cloned!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    if(this != &other) {}
    return *this;
};

std::string DiamondTrap::getName(void) const {
    return (this->name);
}

void DiamondTrap::whoAmi(void) {
    std::cout << getName() << ClapTrap::getName();
}