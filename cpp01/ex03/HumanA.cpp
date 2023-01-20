#include "HumanA.hpp"

std::string HumanA::getName(void)
{
    return(this->name);
}

std::string HumanA::getWeapon(void)
{
    return(this->weapon.getType());
}

void HumanA::attack(void)
{
    std::cout
    << this->getName()
    << " attacks with their "
    << this->getWeapon()
    << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon)
: name(name), weapon(weapon) {};
