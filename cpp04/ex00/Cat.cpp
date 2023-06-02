#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::~Cat() {
	std::cout << type << " went to a better place.\n";
};

void Cat::makeSound() const {
	std::cout << "Cat: Meow!\n";
};

Cat::Cat(const Cat &other) : Animal(other) {
    *this = other;
};

Cat& Cat::operator=(const Cat &other) {
	if(this != &other) {}
    return *this;
};