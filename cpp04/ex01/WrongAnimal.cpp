#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "Created Default WrongAnimal Class object.\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "Created " << type << " Object from WrongAnimal Class.\n";
};

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal class \"" << type << "\" is no longer available.\n"; 
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	this->type = other.type;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if(this != &other) {
		this->type = other.type;
	}
	return *this;
};


std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound! \n";
}