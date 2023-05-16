#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("default")
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string name) : name(name)
{
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap(void) {};

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other) {}
    return *this;
};

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " 
        << this->name << " attacks " 
        << target << ", causing "
        << this->attackDamage <<" points of damage!\n";
    
    this->energyPoints--;
    //find obj by name?
}
