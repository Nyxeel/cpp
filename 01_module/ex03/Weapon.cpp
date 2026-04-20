/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:33:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 18:34:01 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "iostream"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon \"" << type << "\" constructed" << std::endl;
}

Weapon::Weapon()
{
	std::cout << "Weapon default constructed" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon \"" << type << "\" destroyed" << std::endl;
}

const std::string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
	return;
}