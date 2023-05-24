#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {}

void Cat::makeSound(void) {
    std::cout << "Cat: Meow!\n";
};