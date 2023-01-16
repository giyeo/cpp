#include <iostream>

void    megaphone(int argc, char **argv)
{
    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
        exit(1);
    }
    for(int j = 1; j < argc; j++)
    {
        std::string st = argv[j];
        for(int i = 0; i < st.size(); i++)
            std::cout << (char)toupper(st[i]);
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    megaphone(argc, argv);
    return (0);
}