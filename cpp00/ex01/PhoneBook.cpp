#include "PhoneBook.hpp"

int PhoneBook::counterContacts = 0;

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
	<< "First name: " << this->contact[index].firstName << "\n"
	<< "Last name: " << this->contact[index].lastName << "\n"
	<< "Nickname: " << this->contact[index].nickname << "\n"
	<< "Phone number: " << this->contact[index].phoneNumber << "\n"
	<< "Darkest secret: " << this->contact[index].darkestSecret << "\n";
}

int	isContactEmpty(Contact newUser)
{
	if(newUser.firstName.empty()
	|| newUser.lastName.empty()
	|| newUser.nickname.empty()
	|| newUser.phoneNumber.empty()
	|| newUser.darkestSecret.empty())
		return (1);
	return(0);
}
void PhoneBook::addUser(void)
{
	Contact inputContact;
	std::cout << "First name: ";
	std::getline(std::cin, inputContact.firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, inputContact.lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, inputContact.nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, inputContact.phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, inputContact.darkestSecret);
	if (isContactEmpty(inputContact))
	{
		std::cout << "You must fill all contact fields\n";
		return ;
	}
	contact[PhoneBook::counterContacts % MAX_CONTACTS] = inputContact;
	PhoneBook::counterContacts++;
}

void	PhoneBook::printAvailableContacts(void)
{
	for(int index = 0; index < MAX_CONTACTS; index++)
	{
		if(!contact[index].firstName.empty())
		std::cout << "         " << index
		<< "|" << format(contact[index].firstName)
		<< "|" << format(contact[index].lastName)
		<< "|" << format(contact[index].nickname)
		<< std::endl;
	}
}

void PhoneBook::searchUser(void)
{
	if(PhoneBook::counterContacts == 0)
	{
		std::cout << "No available contacts.\n";
		return ;
	}
	this->printAvailableContacts();
	while(true)
	{
		std::string index;
		std::cout << "insert index of desired contact (press Enter to leave): ";
		try
		{
			int intIndex;
			std::getline(std::cin, index);
			if (index.empty())
				return ;
			std::stringstream ss(index);
			ss >> intIndex;
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
	std::cout << "Welcome to the Awesome PhoneBook!\nAvailable commands: ";
	while(true)
	{
		std::cout << "use (ADD, SEARCH, EXIT): ";
		std::string userOption;
		std::getline(std::cin, userOption);
		if (!userOption.compare("ADD"))
			book.addUser();
		else if (!userOption.compare("SEARCH"))
			book.searchUser();
		else if (!userOption.compare("EXIT"))
			std::exit(0);
	}
}

int main(void)
{
	phoneBook();
	return(0);
}
