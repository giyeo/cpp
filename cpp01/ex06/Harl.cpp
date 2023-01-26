#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout
	<< "[ DEBUG ]\n"
    << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
	<< "I really do!\n"
    << std::endl;
}

void Harl::info(void)
{
    std::cout
	<< "[ INFO ]\n"
    << "I cannot believe adding extra bacon costs more money.\n"
    "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
    << std::endl;
}

void Harl::warning(void)
{
    std::cout
	<< "[ WARNING ]\n"
    << "I think I deserve to have some extra bacon for free.\n"
    "I’ve been coming for years whereas you started working here since last month.\n"
    << std::endl;
}

void Harl::error(void)
{
    std::cout
	<< "[ ERROR ]\n"
    << "This is unacceptable! I want to speak to the manager now.\n"
    << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelOptions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*method[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(size_t i = 0; i < levelOptions->length(); i++)
        if(level == levelOptions[i])
            (this->*method[i])();
}
