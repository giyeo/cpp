#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal &other);
        Animal& operator=(const Animal &other);

        virtual void makeSound(void) const;
		std::string getType() const;
    protected:
        std::string type;
};

#endif