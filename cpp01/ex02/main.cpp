#include <string>
#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &refPTR = brain;

    std::cout
    << &brain << std::endl
    << &stringPTR << std::endl
    << &refPTR << std::endl 
    << std::endl
    << brain << std::endl
    << *stringPTR << std::endl
    << refPTR << std::endl;
    return(0);
}