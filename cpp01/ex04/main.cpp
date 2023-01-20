#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "my_sed.hpp"

std::string readFromFile(char **argv)
{
    std::fstream file(argv[1]);
    if(!file)
        std::exit(1);
    std::string buffer;
    std::getline(file, buffer, '\0');
    return (buffer);
}

void    writeToFile(std::string toReturn, char **argv)
{
    std::fstream outfile(argv[1], std::ios::out);
    outfile << toReturn;
    outfile.close();
}


int main(int argc, char **argv)
{
    if(argc != 4 || !std::string(argv[2]).compare(""))
        return(1);

    std::string buffer = readFromFile(argv);
    std::cout << buffer << std::endl;
    std::cout << my_sed::sed(buffer, argv[2], argv[3]) << std::endl;
    writeToFile(my_sed::sed(buffer, argv[2], argv[3]), argv);
    return(0);
}
// ./exc nice.txt "" "" 
