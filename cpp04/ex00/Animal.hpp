#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        ~Animal();
        Animal(const Animal &other);
        Animal& operator=(const Animal &other);

        virtual void makeSound(void);
    protected:
        std::string type;
};

#endif