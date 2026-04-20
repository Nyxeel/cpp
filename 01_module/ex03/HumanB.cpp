/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:33:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 18:26:41 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "iostream"

HumanB::HumanB()
{
	std::cout << "HumanB default constructed" << std::endl;
	weapon = 0;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << name << " constructed" << std::endl;
	weapon = 0;
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
	if (!weapon)
        return ;
	std:: cout << name << " attacks with their " << weapon->getType() << std::endl;
}

