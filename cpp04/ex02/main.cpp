#include "Cat.hpp"
#include "Dog.hpp"

void	setAllIdeas( Animal *animal, std::string idea ) {
	for ( int i = 0; i < 100; i++ ) {
		animal->setIdea(idea, i);
	}
}

int main(void) {

	int size = 6;
	Animal *array[size];
	for(int i = 0; i < size; i++){
		if(i % 2 == 0)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}

	std::cout << "\n\n";

	for(int i = 0; i < size; i++){
		std::cout << array[i]->getType() << " " << i << "\n";
		if(i % 2 == 0)
			setAllIdeas(array[i], "Woof! Woof!");
		else
			setAllIdeas(array[i], "Nyann! Nyaann!" );
	}

	for(int i = 0; i < size; i++){
		std::cout << array[i]->getType() << i << "\n";
		std::cout << array[i]->getIdea(99) << "\n";
	}

	std::cout << "\n\n";

	Cat *cat = (Cat *)array[0];
	Dog *dog = (Dog *)array[1];

	Cat copyCat(*cat);
	Dog copyDog(*dog);

	std::cout << "\n\n";

	for(int i = 0; i < size; i++){
		delete array[i];
	}

	//Animal *error = new Animal("error");

	return (0);
}