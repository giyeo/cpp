#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__
#include <iostream>
#include <string>

void noEnergyAnnounce( std::string name );
void noHitPointsAnnounce( std::string name );

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(const std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap& operator=(const ClapTrap &other);

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
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
};

#endif