#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

	//Animal *ca = new Animal();

	Animal *array[10];
	for(int i = 0; i < 10; i++){
		if(i % 2 == 0)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}

	for(int i = 0; i < 10; i++){
		delete array[i];
	}

	return (0);
}