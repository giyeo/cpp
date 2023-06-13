#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {}

Dog::~Dog() {
	delete brain;
	std::cout << type << " went to heaven.\n";
};

void Dog::makeSound() const {
    std::cout << "Dog: Woof!\n";
};

Dog::Dog(const Dog &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	this->type = other.type;
};

Dog& Dog::operator=(const Dog &other) {
	if(this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return *this;
};

std::string Dog::getIdea(int index) const {
	if(index > 0 && index < 100)
		return this->brain->ideas[index];
	return "";
}

void Dog::setIdea(std::string idea, int index) {
	if(index > 0 && index < 100)
		this->brain->ideas[index] = idea;
};