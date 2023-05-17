#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default")
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << this->getName() << " has activated.\n";
}

ClapTrap::ClapTrap(const std::string name) : name(name)
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap with the name of " << this->getName() << " has activated.\n";
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->getName() << " has turned off.\n";
};

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap " << this->getName() << " has been cloned!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other) {}
    return *this;
};

void noEnergyAnnounce( std::string name )
{
    std::cout << "ClapTrap " << name << " has no energy left.\n";
}

void noHitPointsAnnounce( std::string name )
{
    std::cout << "ClapTrap " << name << " has no hitPoints left.\n";
}

void ClapTrap::attack(const std::string& target)
{
    if(!this->getEnergyPoints())
        return noEnergyAnnounce(this->getName());
    if(!this->getHitPoints())
        return noHitPointsAnnounce(this->getName());
    std::cout << "ClapTrap " 
        << this->getName() << " attacks " 
        << target << ", causing "
        << this->getAttackDamage() <<" points of damage!\n";
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    // if(!this->getEnergyPoints())
    //     return noEnergyAnnounce(this->getName());
    // if(!this->getHitPoints())
    //     return noHitPointsAnnounce(this->getName());
    (amount > hitPoints) ? this->hitPoints = 0 : this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->getName() << " took " << amount << " of damage, and now has " << this->getHitPoints() << " hitPoints left.\n";
    this->energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(!this->getEnergyPoints())
        return noEnergyAnnounce(this->getName());
    if(!this->getHitPoints())
        return noHitPointsAnnounce(this->getName());
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->getName() << " has recovered " << this->getHitPoints() << " hitPoints!\n";
    this->energyPoints--;
}

std::string ClapTrap::getName(void) const {
    return (this->name);
}

unsigned int ClapTrap::getHitPoints(void) const {
    return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return (this->attackDamage);
}
