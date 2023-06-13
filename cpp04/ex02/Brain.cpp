#include "Brain.hpp"

Brain::Brain() {
	std::cout << "new brain in the town!\n";
}

Brain::~Brain() {
	std::cout << "brain went away.\n";
};

Brain::Brain(const Brain &other) {
    *this = other;
};

Brain& Brain::operator=(const Brain &other) {
	if(this != &other) {}
    return *this;
};
