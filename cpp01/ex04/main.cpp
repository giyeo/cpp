#include "my_sed.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

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
    std::string filename = std::string(argv[1]) + ".replace";
    std::fstream outfile(filename.c_str(), std::ios::out);
    outfile << toReturn;
    outfile.close();
}

int main(int argc, char **argv)
{
    if(argc != 4 
	|| !std::string(argv[2]).compare("")
	|| !std::string(argv[2]).compare(std::string(argv[3])))
        return(1);
    std::string buffer = readFromFile(argv);
    writeToFile(my_sed::sed(buffer, argv[2], argv[3]), argv);
    return(0);
}
