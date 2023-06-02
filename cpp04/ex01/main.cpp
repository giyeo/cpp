#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

	Animal *array[100];
	for(int i = 0; i < 100; i++){
		if(i % 2 == 0)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}

	for(int i = 0; i < 100; i++){
		delete array[i];
	}

	return (0);
}