#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include "contacts.hpp"

class PhoneBook
{

	private:
		Contact contacts[8];
		int currIndex;
		int currContacts;

	public:
		PhoneBook();
		~PhoneBook();

		void AddContact();
		void SearchContact();

};

#endif