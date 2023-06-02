#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::~Dog() {
	std::cout << type << " went to heaven.\n";
};

void Dog::makeSound() const {
    std::cout << "Dog: Woof!\n";
};

Dog::Dog(const Dog &other) : Animal(other) {
    *this = other;
};

Dog& Dog::operator=(const Dog &other) {
	if(this != &other) {}
    return *this;
};