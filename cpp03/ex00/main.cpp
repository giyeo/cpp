#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap robin("Robin");

	std::cout << std::endl;

	robin.attack("Batman");
	std::cout << std::endl;

	robin.takeDamage(4);
	std::cout << std::endl;

	robin.takeDamage(8);
	std::cout << std::endl;

    robin.takeDamage(8);
	std::cout << std::endl;

	robin.beRepaired(23);
	std::cout << std::endl;

	robin.beRepaired(4);
	std::cout << std::endl;
}