/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:38:33 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 21:45:30 by pjelinek         ###   ########.fr       */
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
	Animal(other), type(other.type)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
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

const std::string Dog::getType() const
{
	return (this->type);
}