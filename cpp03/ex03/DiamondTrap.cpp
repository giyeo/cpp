#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap("Default_clap_name"), ScavTrap("Default_clap_name"), name("default")
{
    std::cout << "DiamondTrap " << this->getName() << " has activated.\n";
}

DiamondTrap::DiamondTrap(const std::string name) : FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), name(name)
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

void DiamondTrap::attack(const std::string& target)
{
    if(!this->getHitPoints())
        return noHitPointsAnnounce(this->getName());
    ScavTrap::attack(target);
    this->setEnergyPoints(getEnergyPoints() - 1);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    (amount > getHitPoints())
        ? this->setHitPoints(0)
        : this->setHitPoints(getHitPoints() - amount);
    std::cout << this->getName() << " took " << amount << " of damage, and now has " << this->getHitPoints() << " hitPoints left.\n";
    this->setEnergyPoints(getEnergyPoints() - 1);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    if(!this->getEnergyPoints())
        return noEnergyAnnounce(this->getName());
    if(!this->getHitPoints())
        return noHitPointsAnnounce(this->getName());
    this->setHitPoints(getHitPoints() + amount);
    std::cout << this->getName() << " has recovered " << amount << " hitPoints!\n";
    this->setEnergyPoints(getEnergyPoints() - 1);
}

unsigned int DiamondTrap::getHitPoints(void) const {
    return (this->FragTrap::getHitPoints());
}

unsigned int DiamondTrap::getEnergyPoints(void) const {
    return (this->ScavTrap::getHitPoints());
}

unsigned int DiamondTrap::getAttackDamage(void) const {
    return (this->FragTrap::getHitPoints());
}

void DiamondTrap::setHitPoints(unsigned int hitPoints) {
    this->FragTrap::setHitPoints(hitPoints);
}

void DiamondTrap::setEnergyPoints(unsigned int energyPoints) {
    this->ScavTrap::setHitPoints(energyPoints);
}

void DiamondTrap::setAttackDamage(unsigned int attackDamage) {
    this->FragTrap::setAttackDamage(attackDamage);
}

std::string DiamondTrap::getName(void) const {
    return (this->name);
}