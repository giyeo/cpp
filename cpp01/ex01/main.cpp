#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void    announceHorde(Zombie *horde, int N)
{
	for(int i = 0; i < N; i++)
		horde[i].announce();
}

int main(void)
{   
	int num = 2;
	Zombie *horde = zombieHorde(num, "crepy");
	announceHorde(horde, num);
	delete[] horde;

	num = 0;
	horde = zombieHorde(num, "brody");
	announceHorde(horde, num);
	delete[] horde;

	num = 1;
	horde = zombieHorde(num, "maxx");
	announceHorde(horde, num);
	delete[] horde;

	num = 4;
	horde = zombieHorde(num, "madelene");
	announceHorde(horde, num);
	delete[] horde;
	return(0);
}