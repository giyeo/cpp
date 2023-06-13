#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::~Dog() {
	std::cout << type << " went to heaven.\n";
};

void Dog::makeSound() const {
    std::cout << "Dog: Woof!\n";
};

Dog::Dog(const Dog &other) : Animal(other) {
	this->type = other.type;
};

Dog& Dog::operator=(const Dog &other) {
	if(this != &other) {
		this->type = other.type;
	}
	return *this;
};