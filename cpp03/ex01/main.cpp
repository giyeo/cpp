#include "ScavTrap.hpp"

void    printStatus(ScavTrap& privs) {
	std::cout << "Name: " << privs.getName() << std::endl;
	std::cout << "Hit points: " << privs.getHitPoints() << std::endl;
	std::cout << "Energy points: " << privs.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << privs.getAttackDamage() << std::endl;
}

int main( void ) {
	ScavTrap privs;

	printStatus(privs);
	std::cout << std::endl;
	privs.guardGate();
	std::cout << std::endl;

	privs.attack("Gadino");
	printStatus(privs);
	std::cout << std::endl;

	privs.takeDamage(10);
	printStatus(privs);
	std::cout << std::endl;

	privs.beRepaired(1);
	printStatus(privs);
	std::cout << std::endl;
	return (0);
}