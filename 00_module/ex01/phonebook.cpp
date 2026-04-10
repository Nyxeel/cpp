/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/10 13:51:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "stdlib.h"

PhoneBook::PhoneBook() {
  std::cout << "PhoneBook constructed" << std::endl;
  currIndex = 1;
  currContacts = 0;
}

PhoneBook::~PhoneBook() { std::cout << "PhoneBook destructed" << std::endl; }

void PhoneBook::AddContact() {
  std::string input;
  if (currIndex == 8)
    currIndex = 1;
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
  currIndex++;
  if (currContacts < 7)
    currContacts++;
}

int PhoneBook::checkNumber(std::string input) {
  if (input.size() > 1) {
    std::cout << "Please enter only 1-digit" << std::endl;
    return (0);
  }
  if (input.empty()) {
    std::cout << "Emtpy input - Try again" << std::endl;
    return (0);
  }

  for (int i = 0; input[i]; i++)
    if (!isdigit(input[i])) {
      std::cout << "Only digits allowed" << std::endl;
      return (0);
    }

  index = atoi(input.c_str());

  if (index < 1 || index > currContacts) {
    std::cout << "Index out of range" << std::endl;
    return (0);
  }
  return (1);
}

void PhoneBook::SearchContact() {
  std::string input;

  if (currContacts == 0) {
    std::cout << "No Contacts in PhoneBook atm" << std::endl;
    return;
  }
  do {
    std::cout << "Enter Contact Index from 1 - 8 to display contact"
              << std::endl;
    std::getline(std::cin, input);
  } while (checkNumber(input));
}
