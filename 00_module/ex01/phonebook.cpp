/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/11 19:34:01 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "stdlib.h"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
  std::cout << "PhoneBook constructed" << std::endl;
  currIndex = 0;
  currContacts = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructed" << std::endl;
}

void PhoneBook::AddContact()
{
	std::string input;
	if (currIndex == 8)
	  currIndex = 0;
	// FIRST NAME
	do {
	  std::cout << "Enter First Name" << std::endl;
	  std::getline(std::cin, input);
	} while (input.empty());
	contacts[currIndex].setFirstName(input);
	// LAST NAME
	do {
	  std::cout << "Enter Last Name" << std::endl;
	  std::getline(std::cin, input);
	} while (input.empty());
	contacts[currIndex].setLastName(input);

	// NICK NAME
	do {
	  std::cout << "Enter Nick Name" << std::endl;
	  std::getline(std::cin, input);
	} while (input.empty());
	contacts[currIndex].setNickName(input);

	// PHONE NUMBER
	do {
	  std::cout << "Enter Phone Number" << std::endl;
	  std::getline(std::cin, input);
	} while (input.empty());
	contacts[currIndex].setPhoneNumber(input);

	// DARK SECRET
	do {
	  std::cout << "Enter Dark Secret" << std::endl;
	  std::getline(std::cin, input);
	} while (input.empty());
	contacts[currIndex].setDarkSecret(input);

	std::cout << "Contact added" << std::endl;
	if (currIndex < 8)
		currIndex++;
	if (currContacts < 7)
	    currContacts++;
}

int PhoneBook::checkNumber(std::string input)
{
	if (input.empty()) {
	  std::cout << "Empty input - Try again" << std::endl;
	  return (0);
	}
	if (input.size() > 1) {
	  std::cout << "Please enter only 1-digit" << std::endl;
	  return (0);
	}
	for (int i = 0; input[i]; i++)
	  if (!isdigit(input[i])) {
	    std::cout << "Only digits allowed" << std::endl;
	    return (0);
	  }
	index = atoi(input.c_str());
	if (index < 0 || index > currContacts - 1) {
	  std::cout << "Index out of range" << std::endl;
	  return (0);
	}
	return (1);
}

std::string PhoneBook::formatString(std::string name)
{
	if (name.size() > 10)
		return(name.substr(0, 9) + ".");
	return (name);
}

void PhoneBook::printContact()
{

	std::cout << std::setw(10) << std::right << index << "|" ;
	std::cout << std::setw(10) << std::right << formatString(contacts[index].getFirstName()) << "|" ;
	std::cout << std::setw(10) << std::right << formatString(contacts[index].getLastName()) << "|" ;
	std::cout << std::setw(10) << std::right << formatString(contacts[index].getNickName()) << "|" ;
	std::cout << std::endl;
}

void PhoneBook::SearchContact() {
  std::string input;

	if (currContacts == 0) {
	  std::cout << "No Contacts in PhoneBook atm" << std::endl;
	  return;
	}
	do
	{
	  std::cout << "Enter Contact Index from 0 - 7 to display contact"
	            << std::endl;
	  std::getline(std::cin, input);
	} while (!checkNumber(input));
	printContact();
}
