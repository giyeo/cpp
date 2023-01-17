#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include <iostream>

class Zombie{
    public:
        void announce( void );

        Zombie ( std::string name);
        ~Zombie ( void );

        std::string getName( void ) const;
        void setName( std::string name );
    private:
        std::string _name;
};


#endif