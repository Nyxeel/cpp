/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 23:48:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm " << target << " constructor called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other)
{
	std::cout << "PresidentialPardonForm " << target << " copy constructor called " << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm " << target << " copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << target << " destructor called" << std::endl;
}

void 		PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
