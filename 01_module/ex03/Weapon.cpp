/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:33:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/12 21:46:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "iostream"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
	std::cout << type << " destroyed" << std::endl;
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