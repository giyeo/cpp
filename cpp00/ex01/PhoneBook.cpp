#include <iostream>
#include "phoneBook.hpp"

std::string format(std::string toFormat)
{
	while(toFormat.length() < 10)
		toFormat = " " + toFormat;
	if(toFormat.length() > 10)
	{
		toFormat.resize(9);
		toFormat = toFormat + ".";
	}
	return (toFormat);
}

void PhoneBook::printContact(int index)
{
	std::cout
	<< this->contact[index].firstName << "\n"
	<< this->contact[index].lastName << "\n"
	<< this->contact[index].nickname << "\n"
	<< this->contact[index].phoneNumber << "\n"
	<< this->contact[index].darkestSecret << "\n";
}

void PhoneBook::addUser(void)
{
	Contact inputContact;
	std::cout << "first name: ";
	std::cin >> inputContact.firstName; 
	std::cout << "last name: ";
	std::cin >> inputContact.lastName;
	std::cout << "nickname: ";
	std::cin >> inputContact.nickname; 
	std::cout << "phone number: ";
	std::cin >> inputContact.phoneNumber; 
	std::cout << "darkest secret: ";
	std::cin >> inputContact.darkestSecret;
	contact[counterContacts % MAX_CONTACTS] = inputContact;
	this->counterContacts++;
}

void	PhoneBook::printAvailableContacts(void)
{
	for(int index = 0; index < MAX_CONTACTS; index++)
	{
		if(!contact[index].firstName.empty())
		std::cout << index
		<< "|" << format(contact[index].firstName)
		<< "|" << format(contact[index].lastName)
		<< "|" << format(contact[index].nickname)
		<< std::endl;
	}
}

void PhoneBook::searchUser(void)
{
	this->printAvailableContacts();
	while(true)
	{
		std::string index;
		std::cout << "insert index of desired contact (-1 to leave): ";
		try
		{
			std::cin >> index;
			int intIndex = stoi(index);
			if (intIndex == -1)
				return ;
			if (intIndex < 0 || intIndex > 8 || this->contact[intIndex].firstName.empty())
				std::cout << "index out of range, please, type a valid number!\n";
			else
			{
				this->printContact(intIndex);
				return ;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "please, type a number!\n";
		}
	}
}

void	phoneBook(void)
{
	PhoneBook book;
	std::cout << "Welcome to the Awesome PhoneBook!\n";
	std::cout << "Available commands: ";
	while(true)
	{
		std::cout << "(ADD, SEARCH, EXIT): ";
		std::string userOption;
		std::cin >> userOption;
		if (!userOption.compare("ADD"))
			book.addUser();
		if (!userOption.compare("SEARCH"))
			book.searchUser();
		if (!userOption.compare("EXIT"))
			exit(0);
	}
}

int main(void)
{
	phoneBook();
	return(0);
}
