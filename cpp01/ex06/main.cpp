#include "Harl.hpp"

int	coutCascade(int level)
{
	Harl logger;

	switch (level)
	{
		case 0:
			logger.complain("DEBUG");
			__attribute__ ((fallthrough));
		case 1:
			logger.complain("INFO");
			__attribute__ ((fallthrough));
		case 2:
			logger.complain("WARNING");
			__attribute__ ((fallthrough));
		case 3:
			logger.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return(0);
}

int main(int argc, char **argv)
{
	if(argc != 2)
		return (0);
	std::string levelOptions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < 4; i++)
	{
		if (!levelOptions[i].compare((std::string)argv[1]))
			return(coutCascade(i));
	}
	return (coutCascade(4));
}
