#include <cstdio>
#include <ctime>
#include <iostream>
#include "Account.hpp"
#include <string>
#include <stdlib.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return(Account::_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return(Account::_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return(Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return(Account::_totalNbWithdrawals);
}
int	Account::checkAmount(void) const
{
	return(this->_amount);
}

Account::Account(int initialDeposit)
{
	this->_amount = 0;
	this->_nbDeposits = -1;
	this->_nbWithdrawals = 0;
	this->makeDeposit(initialDeposit);
	this->_accountIndex = this->_nbAccounts++;
	this->_displayTimestamp();
	std::cout 
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << initialDeposit << ";"
	<< "created\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t	rawtime;
	std::tm		*timeinfo;
	char buffer [80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
	<< "accounts:" << Account::getNbAccounts() << ";"
	<< "total:" << Account::getTotalAmount() << ";"
	<< "deposits:" << Account::getNbDeposits() << ";"
	<< "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	if (this->_nbDeposits != 0)
	{
		this->_totalNbDeposits++;
		Account::_displayTimestamp();
		std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << "\n";
	}
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool refused = false;
	if(this->_amount - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
	}
	else
		refused = true;
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount + (refused ? 0 : withdrawal) << ";"
	<< "withdrawal:";
	if (refused)
		std::cout << "refused\n";
	else
		std::cout << withdrawal << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (!refused);
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "closed\n";
}