#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    const std::string targ = "f";
    const std::string& target = targ;
    std::cout << target << '\n';
    a.attack(target);
    return (0);
}