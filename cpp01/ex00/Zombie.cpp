#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

std::string Zombie::getName(void) const
{
    return (this->_name);
}

void Zombie::announce(void)
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..."
    << std::endl;
}

Zombie::Zombie( std::string name ){
    this->setName(name);
}

Zombie::~Zombie( void )
{
    std::cout << this->getName() << " died"
    << std::endl;
}
