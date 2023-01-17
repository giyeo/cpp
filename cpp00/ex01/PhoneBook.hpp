#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <sstream>
# define MAX_CONTACTS 8
class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

class PhoneBook
{   
	public:
		Contact contact[8];
		static int counterContacts;
		void addUser(void);
		void printContact(int index);
		void searchUser(void);
		void printAvailableContacts(void);
};

#endif