#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "contacts.hpp"

class PhoneBook
{

	private:
		Contact contacts[8];
		int		checkNumber(std::string input);
		void	printContact();
		std::string formatString(std::string name);
		int		currIndex;
		int		currContacts;
		int		index;

	public:
		PhoneBook();
		~PhoneBook();

		void	AddContact();
		void	SearchContact();
};

#endif