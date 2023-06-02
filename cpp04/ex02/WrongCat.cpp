#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}

WrongCat::~WrongCat() {
	std::cout << type << " went to a better place.\n";
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    *this = other;
};

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if(this != &other) {}
    return *this;
};