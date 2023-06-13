#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {}

Cat::~Cat() {
	delete brain;
	std::cout << type << " went to a better place.\n";
};

void Cat::makeSound() const {
	std::cout << "Cat: Meow!\n";
};

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	this->type = other.type;
};

Cat& Cat::operator=(const Cat &other) {
	if(this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return *this;
};

std::string Cat::getIdea(int index) const {
	if(index > 0 && index < 100)
		return this->brain->ideas[index];
	return "";
}

void Cat::setIdea(std::string idea, int index) {
	if(index > 0 && index < 100)
		this->brain->ideas[index] = idea;
};