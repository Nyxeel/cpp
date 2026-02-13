/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:33:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/12 21:59:12 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "iostream"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon)
{
	std::cout << name << " constructed" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " destroyed" << std::endl;
}

void HumanA::attack()
{
	std:: cout << name << " attacks with their " << weapon.getType() << std::endl;
}

