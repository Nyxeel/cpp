/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 23:48:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm " << target << " constructor called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other)
{
	std::cout << "RobotomyRequestForm " << target << " copy constructor called " << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm " << target << " copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << target << " destructor called" << std::endl;
}

void 		RobotomyRequestForm::executeAction() const
{
	int randomNum = rand() % 101;

	if (randomNum % 2 == 0)
		std::cout << "Brrrrr... zzzzzzt... whirrrrr... grrrrrnk... drrr-drrr-drrr..." \
		<< target <<  " hab been robotomized" << std::endl;
	else
		std::cout << "Too bad. The robotomy failed." << std::endl;

}