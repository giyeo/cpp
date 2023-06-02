#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal {
	public:
        virtual ~Animal();
        Animal& operator=(const Animal &other);
        virtual void makeSound(void) const;
		std::string getType() const;
    protected:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);

        std::string type;
};

#endif