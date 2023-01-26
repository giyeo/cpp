#include "Harl.hpp"

int main(void)
{
    Harl logger;
    
    std::string testStrings[6] = {"DEBUG", "INFO", "WARNING", "ERROR", "", "ANY"};
    for(size_t i = 0; i < testStrings->length(); i++)
        logger.complain(testStrings[i]);
    return(0);
}