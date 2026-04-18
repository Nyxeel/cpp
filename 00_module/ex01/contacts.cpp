/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 00:15:00 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"
#include <iostream>

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

std::string Contact::getFirstName()
{
	return (firstName);
}

std::string Contact::getLastName()
{
	return (lastName);
}

std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string Contact::getDarkSecret()
{
	return (darkSecret);
}

std::string Contact::getNickName()
{
	return (nickName);
}