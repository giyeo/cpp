#include <iostream>
#include <cstdlib>

void    megaphone(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
        std::exit(1);
    }
    for (size_t j = 1; j < (size_t)argc; j++)
    {
        std::string current = argv[j];
        for (size_t i = 0; i < current.size(); i++)
            std::cout << (char)toupper(current[i]);
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    megaphone(argc, argv);
    return (0);
}