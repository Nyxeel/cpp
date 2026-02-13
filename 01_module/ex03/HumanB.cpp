/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:33:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/12 22:18:12 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "iostream"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << name << " constructed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << name << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std:: cout << name << " attacks with their " << weapon->getType() << std::endl;
}

