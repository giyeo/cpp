#include <cstdio>
#include <ctime>
#include <iostream>
#include "Account.hpp"

Account::~Account()
{

}

Account::Account(int initialDeposit)
{
	this->_nbAccounts++;
	this->_nbDeposits++;
}

void	displayTime(void)
{
	std::time_t	rawtime;
	std::tm		*timeinfo;
	char buffer [80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << '\n';
}

int	getInitialDeposit(void)
{
	int initialDeposit;
	while (true)
	{
		std::cout << "Initial Deposit: ";
		try{
			std::cin >> initialDeposit;
			if (initialDeposit < 0)
				std::cout << "Please, type an positive ammount to deposit!\n";
			else
				return (initialDeposit);
		}
		catch(const std::exception& e)
		{ std::cerr << "Please, type a valid number" << '\n'; }
	}
}

void	bank(void)
{
	std::cout << "Welcome do the World's first Bank!, please make your first deposit in order to start!\n";
	Account accounts(getInitialDeposit());

}

int main (void)
{
	bank();
    return (0);
}
