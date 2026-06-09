/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:57:51 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/09 20:42:10 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}
Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

const char* Intern::FormNotExisting::what() const throw()
{
	return("This form name is not existing.");
}

AForm*	createPresidential(const std::string &target)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm*	createRobotomy(const std::string &target)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm*	createShrubbery(const std::string &target)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return (new ShrubberyCreationForm(target));
}


AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string internNames[] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	FormCreator creator[] =
	{
		createPresidential,
		createRobotomy,
		createShrubbery
	};

	for (int i = 0; i < 3; i++){
		if (formName == internNames[i])	{
			return (creator[i](target));
		}
	}
	throw Intern::FormNotExisting();
}