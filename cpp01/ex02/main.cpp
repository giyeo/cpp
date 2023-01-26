#include <string>
#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout
    << &brain << std::endl
    << &stringPTR << std::endl
    << &stringREF << std::endl 
    << std::endl
    << brain << std::endl
    << *stringPTR << std::endl
    << stringREF << std::endl;
    return(0);
}