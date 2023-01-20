#include "my_sed.hpp"

std::string my_sed::sed(std::string src, std::string toFind, std::string toBe)
{
    size_t index = 0;
    int i = 0;
    while(index != std::string::npos)
    {
        src = (src.substr(0, index))
        + ((bool)i ? toBe : "")
        + src.substr(index + (toFind.length() * (bool)i));
        index = src.find(toFind);
        i = 1;
    }
    return(src);
}