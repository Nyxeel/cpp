/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 00:15:37 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "stdlib.h"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() {
  std::cout << "PhoneBook constructed" << std::endl;
  currIndex = 0;
  currContacts = 0;
}

PhoneBook::~PhoneBook() { std::cout << "PhoneBook destructed" << std::endl; }

void PhoneBook::AddContact() {
  std::string input;
  if (currIndex == 8)
    currIndex = 0;
  // FIRST NAME
  do {
    std::cout << "Enter First Name" << std::endl;
    if (!std::getline(std::cin, input))
      break;
  } while (input.empty());
  contacts[currIndex].setFirstName(input);
  // LAST NAME
  do {
    std::cout << "Enter Last Name" << std::endl;
    if (!std::getline(std::cin, input))
      break;
  } while (input.empty());
  contacts[currIndex].setLastName(input);
  // NICK NAME
  do {
    std::cout << "Enter Nick Name" << std::endl;
    if (!std::getline(std::cin, input))
      break;
  } while (input.empty());
  contacts[currIndex].setNickName(input);
  // PHONE NUMBER
  do {
    std::cout << "Enter Phone Number" << std::endl;
    if (!std::getline(std::cin, input))
      break;
  } while (input.empty());
  contacts[currIndex].setPhoneNumber(input);
  // DARK SECRET
  do {
    std::cout << "Enter Dark Secret" << std::endl;
    if (!std::getline(std::cin, input))
      break;
  } while (input.empty());
  contacts[currIndex].setDarkSecret(input);
  std::cout << "Contact added" << std::endl;
  if (currIndex < 8)
    currIndex++;
  if (currContacts < 8)
    currContacts++;
}

int PhoneBook::checkNumber(std::string input) {
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

std::string PhoneBook::formatString(std::string name) {
  if (name.size() > 10)
    return (name.substr(0, 9) + ".");
  return (name);
}

void PhoneBook::printPhonebook() {
  std::cout << std::setw(10) << std::right << "Index" << "|";
  std::cout << std::setw(10) << std::right << "Name" << "|";
  std::cout << std::setw(10) << std::right << "Last Name" << "|";
  std::cout << std::setw(10) << std::right << "Nickname" << "|";
  std::cout << std::endl;

  for (int idx = 0; idx < currContacts; idx++) {
    std::cout << std::setw(10) << std::right << idx << "|";
    std::cout << std::setw(10) << std::right
              << formatString(contacts[idx].getFirstName()) << "|";
    std::cout << std::setw(10) << std::right
              << formatString(contacts[idx].getLastName()) << "|";
    std::cout << std::setw(10) << std::right
              << formatString(contacts[idx].getNickName()) << "|";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
void PhoneBook::printContact() {
  std::cout << std::endl;
  std::cout << "Index: " << index << std::endl;
  std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
  std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
  std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
  std::cout << "Phone Number: " << contacts[index].getPhoneNumber()
            << std::endl;
  std::cout << "Dark Secret: " << contacts[index].getDarkSecret() << std::endl;
  std::cout << std::endl;
}

void PhoneBook::SearchContact() {
  std::string input;

  if (currContacts == 0) {
    std::cout << "No Contacts in PhoneBook atm" << std::endl;
    return;
  }
  printPhonebook();
  do {
    std::cout << "Enter Contact Index from 0 - " << currContacts - 1
              << " to display contact" << std::endl;
    if (!std::getline(std::cin, input))
      return;
  } while (!checkNumber(input));
  printContact();
}
