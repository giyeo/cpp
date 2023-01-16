#include <iostream>

class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#define MAX_CONTACTS 8

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

class PhoneBook
{   
	public:
		Contact contact[8];
		int counterContacts = 0;
		void addUser(void)
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

		void printContact(int index)
		{
			std::cout << this->contact[index].firstName << "\n"
			<< this->contact[index].lastName << "\n"
			<< this->contact[index].nickname << "\n"
			<< this->contact[index].phoneNumber << "\n"
			<< this->contact[index].darkestSecret << "\n";
		}

		void searchUser(void)
		{
			std::string index;
			int	intIndex = -1;
			for(int index = 0; index < MAX_CONTACTS; index++)
				std::cout << index
				<< "|" << format(contact[index].firstName)
				<< "|" << format(contact[index].lastName)
				<< "|" << format(contact[index].nickname)
				<< std::endl;
			std::cout << "insert index of desired contact: ";
			std::cin >> index;
			try
			{
				intIndex = stoi(index);
			}
			catch(const std::exception& e)
			{
				std::cerr << "cannot parse the number\n";
			}
			if(intIndex < 0 || intIndex > 8)
			{
				std::cout << "index out of range, please, type a valid number\n";
			}
			else
				this->printContact(intIndex);
		}
};

int main(void)
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
	return(0);
}
