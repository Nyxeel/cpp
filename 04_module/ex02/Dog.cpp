/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:38:33 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 15:17:43 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog &other) :
	AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (brain)
		{
			delete brain;
			brain = new Brain(*other.brain);
		}
		else
			brain = new Brain();
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "\"WUFF WUFF\"" << std::endl;
}
