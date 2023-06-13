#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "Created Default Animal Class object.\n";
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Created " << type << " Object from Animal Class.\n";
};

Animal::~Animal(void) {
	std::cout << "Animal class \"" << type << "\" is dead.\n"; 
};

Animal::Animal(const Animal &other) {
	this->type = other.type;
};

Animal& Animal::operator=(const Animal &other) {
	if(this != &other) {
		this->type = other.type;
	}
	return *this;
};

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound! \n";
}
