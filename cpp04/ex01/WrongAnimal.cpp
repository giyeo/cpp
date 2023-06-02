#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "Created Default WrongAnimal Class object.\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "Created " << type << " Object from WrongAnimal Class.\n";
};

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal class \"" << type << "\" is dead.\n"; 
};

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if(this != &other) {}
    return *this;
};

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound! \n";
}