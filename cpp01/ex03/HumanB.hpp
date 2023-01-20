#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    public:

        void attack(void);

        HumanB(std::string name);

        std::string getName(void);
        Weapon getWeapon(void);
        void setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon *weapon;
};

#endif