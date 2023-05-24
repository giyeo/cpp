#include "Animal.hpp"

Animal::Animal(void) {}

Animal::Animal(std::string type) : type(type) {};

Animal::~Animal(void) {};

Animal::Animal(const Animal &other)
{
    *this = other;
}

Animal& Animal::operator=(const Animal &other)
{
    if(this != &other) {}
    return *this;
};