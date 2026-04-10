/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/10 10:58:27 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
	if (currIndex == 7)
		currIndex = 0;
	std::cout << "Enter First Name" << std::endl;
	std::getline(std::cin, contacts[currIndex].FirstName);

}
