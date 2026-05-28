/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 15:36:28 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	name = "JohnLow";
	std::cout << "Bureaucrat default constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called " << std::endl;
}



Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		grade = other.grade;
	}
	return (*this);

}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}
