#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <cstring>

class Contact
{
	private:

	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkSecret;

	public:
		Contact();
		~Contact();

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkSecret(std::string darkSecret);

};

#endif