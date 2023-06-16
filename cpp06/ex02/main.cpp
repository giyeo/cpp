#include "Classes.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>

char getRandomABC() {
	srand(time(0));
	int random = rand() % 3;
	if (random == 0)
		return 'A';
	if (random == 1)
		return 'B';
	return 'C';
}

Base *makeClassA() {
	return (new A);
}

Base *makeClassB() {
	return (new B);
}

Base *makeClassC() {
	return (new C);
}

Base * generate(void) {
	char randomChar = getRandomABC();
	char classes[3] = {'A', 'B', 'C'};
	Base *(*makeClasses[3])() = {
		&makeClassA,
		&makeClassB,
		&makeClassC
	};
	for (size_t i = 0; i < 3; i++) {
		if (classes[i] == randomChar) {
			return ((makeClasses[i])());
		}
	}
	return NULL;
};

void identify(Base* p) {
	if (p == NULL)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "I don't know" << std::endl;
}

void    identify(Base& p) {
	try { (void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (...) {}

	try { (void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (...) {}

	try { (void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (...) {}
}

int main() {
	Base *n = generate();
	identify(n);
	identify(*n);
	delete n;
	return(0);
}