#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    public:
        void attack(void);

        HumanA(std::string name, Weapon& weapon);

        std::string getName(void);
        std::string getWeapon(void);
    private:
        std::string name;
        Weapon &weapon;
};

#endif