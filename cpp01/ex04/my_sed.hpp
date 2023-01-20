#ifndef __MY_SED_HPP__
#define __MY_SED_HPP__

#include <string>

class my_sed
{
    public:
        static std::string sed(std::string src, std::string toFind, std::string toBe);
};

#endif