#include "HumanB.hpp"

Weapon HumanB::getWeapon(void)
{
    return (*this->weapon);
}

std::string HumanB::getName(void)
{
    return (this->name);
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void)
{
    std::cout
    << this->getName()
    << " attacks with their "
    << this->getWeapon().getType()
    << std::endl;
}

HumanB::HumanB(std::string name):name(name) {}
