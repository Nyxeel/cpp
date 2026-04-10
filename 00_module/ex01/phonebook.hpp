#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include "contacts.hpp"

class PhoneBook
{

	private:
		Contact contacts[8];
		int checkNumber(std::string input);
		int currIndex;
		int currContacts;
		int index;

	public:
		PhoneBook();
		~PhoneBook();

		void AddContact();
		void SearchContact();

};

#endif