#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(const std::string name);
        ~FragTrap();
        FragTrap(const FragTrap &other);
        FragTrap& operator=(const FragTrap &other);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif