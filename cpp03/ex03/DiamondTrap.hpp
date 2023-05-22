#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(const std::string name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap& operator=(const DiamondTrap &other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void)const;
        unsigned int getHitPoints(void) const;
        unsigned int getEnergyPoints(void) const;
        unsigned int getAttackDamage(void) const;
        void setAttackDamage(unsigned int attackDamage);
        void setEnergyPoints(unsigned int energyPoints);
        void setHitPoints(unsigned int hitPoints);
    private:
        const std::string name;
};

#endif