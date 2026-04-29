/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:53:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/29 21:34:47 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hitPoints = 100;
  	energyPoints = 50;
  	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	hitPoints = 100;
  	energyPoints = 50;
  	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
  if (!energyPoints) {
    std::cout << "ScavTrap "<< name << " has not enough energy points to attack" << std::endl;
  	std::cout << std::endl;
	return ;
  }
  if (!hitPoints) {
    std::cout << "ScavTrap " << name << " is dead and can't attack " << target << std::endl;
  	std::cout << std::endl;
    return ;
  }
  this->energyPoints--;
  std::cout << "ScavTrap " << this->name << " attacks ";
  std::cout << target << ", causing " << attackDamage;
  std::cout << " points of damage!" << std::endl;
  std::cout << this->name << " has " << energyPoints << " energy points left!" << std::endl;
  std::cout << std::endl;
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " ist jetzt im GateKeeper mode" << std::endl;
}