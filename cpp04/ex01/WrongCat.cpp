#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}

WrongCat::~WrongCat() {
	std::cout << type << " went to a better place.\n";
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	this->type = other.type;
};

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if(this != &other) {
		this->type = other.type;
	}
	return *this;
};

void WrongCat::makeSound() const{
	std::cout << "WrongCat Sound! \n";
}