/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:50:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/24 17:12:45 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
  std::cout << "Default Constructor called" << std::endl;
  hitPoints = 10;
  energyPoints = 10;
  attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : name(name) {
  std::cout << "Constructor " << name << " called" << std::endl;
  hitPoints = 10;
  energyPoints = 10;
  attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (!energyPoints) {
    std::cout << name << " has not enough energy points to attack" << std::endl;
    return;
  }
  this->energyPoints--;
  std::cout << "ClapTrap " << this->name << " attacks ";
  std::cout << target << ", causing " << attackDamage;
  std::cout << " points of damage!" << std::endl;
  std::cout << this->name << " has " << energyPoints << " energy points left!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount) {

  if (hitPoints - (int) amount <= 0)
    hitPoints = 0;
  else
    hitPoints -= amount;
  std::cout << "ClapTrap " << this->name << " takes ";
  std::cout << amount << " damage and has " << this->hitPoints;
  std::cout << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->energyPoints) {
    std::cout << "Not enough energy points to repair" << std::endl;
    return;
  }
  this->energyPoints--;
  this->hitPoints += amount;
  std::cout << "ClapTrap " << this->name << " repairs itselft and regains ";
  std::cout << amount << " of hit points and has now";
  std::cout << this->hitPoints << " hit points!" << std::endl;
}
