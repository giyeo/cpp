#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal {
    public:
        virtual ~Animal();
        Animal& operator=(const Animal &other);

		virtual std::string getIdea(int index) const = 0;
		virtual void setIdea(std::string idea, int index) = 0;

        virtual void makeSound(void) const = 0;
		std::string getType() const;
    protected:
        std::string type;
		Animal();
        Animal(std::string type);
        Animal(const Animal &other);
};

#endif