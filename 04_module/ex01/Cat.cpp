/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:38:33 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 21:45:36 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat &other) :
	Animal(other), type(other.type)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		if (brain)
		{
			delete brain;
			brain = new Brain (*other.brain);
		}

	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "\"MIAUUUUU\"" << std::endl;
}
const std::string Cat::getType() const
{
	return (this->type);
}