/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/10 11:56:39 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact()
{
	std::cout << "Contact constructed" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destructed" << std::endl;
}

void Contact::setFirstName(std::string name)
{
	this->firstName = name;
}

void Contact::setLastName(std::string name)
{
	this->lastName = name;
}

void Contact::setNickName(std::string name)
{
	this->nickName = name;
}
void Contact::setPhoneNumber(std::string name)
{
	this->phoneNumber = name;
}
void Contact::setDarkSecret(std::string name)
{
	this->darkSecret = name;
}
