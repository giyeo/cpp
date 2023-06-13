#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const Animal* capivara = new Animal("Capivara");
    std::cout << std::endl;

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << capivara->getType() << " " << std::endl;
    std::cout << std::endl;

    dog->makeSound();
    cat->makeSound();
    capivara->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;
    delete capivara;
    std::cout << std::endl;

	const Animal* cat2 = new Cat();
	std::cout << cat2->getType() << " " << std::endl;
	cat2->makeSound();
	delete cat2;

    const WrongAnimal* wcat = new WrongCat();

    std::cout << wcat->getType() << " " << std::endl;
    wcat->makeSound();
    delete wcat;

    return 0;
}