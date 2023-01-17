#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    Zombie billy = Zombie("billy");
    billy.announce();
    
    randomChump("alice");

    Zombie *mark = newZombie("mark");
    mark->announce();
    delete mark;
    
    return(0);
}