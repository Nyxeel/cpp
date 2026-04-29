/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:50:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/26 14:32:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
  	std::cout << "ClapTrap default constructor called" << std::endl;
  	name = "";
 	hitPoints = 10;
  	energyPoints = 10;
  	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
  	std::cout << "ClapTrap constructor " << name << " called" << std::endl;
 	hitPoints = 10;
  	energyPoints = 10;
  	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	name(other.name), hitPoints(other.hitPoints),
	energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "Clap Trap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment constructor called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (!energyPoints) {
    std::cout << name << " has not enough energy points to attack" << std::endl;
  	std::cout << std::endl;
	return ;
  }
  if (!hitPoints) {
    std::cout << name << " is dead and can't attack " << target << std::endl;
  	std::cout << std::endl;
    return ;
  }
  this->energyPoints--;
  std::cout << "ClapTrap " << this->name << " attacks ";
  std::cout << target << ", causing " << attackDamage;
  std::cout << " points of damage!" << std::endl;
  std::cout << this->name << " has " << energyPoints << " energy points left!" << std::endl;
  std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (!hitPoints)
	{
		std::cout << this->name << " is already dead!" << std::endl;
  		std::cout << std::endl;
		return ;
	}
	else if (hitPoints - (int) amount <= 0)
    	hitPoints = 0;
	else
	  hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes ";
	std::cout << amount << " damage and has " << this->hitPoints;
	std::cout << " hit points left!" << std::endl;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->energyPoints) {
    std::cout  << name <<  " has not enough energy points to repair the damage!" << std::endl;
  	std::cout << std::endl;
    return ;
  }
  if (!this->hitPoints) {
    std::cout  << name <<  " is dead and can't repair damage!" << std::endl;
 	std::cout << std::endl;
    return ;
  }
  this->energyPoints--;
  this->hitPoints += amount;
  std::cout << "ClapTrap " << this->name << " repairs itself and regains ";
  std::cout << amount << " hit points and has now ";
  std::cout << this->hitPoints << " hit points!" << std::endl;
  std::cout << this->name << " has " << energyPoints << " energy points left!" << std::endl;
  std::cout << std::endl;
}
