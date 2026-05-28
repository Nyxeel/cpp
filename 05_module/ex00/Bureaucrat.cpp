/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 22:39:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade) :
	name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << name << " constructor called " << std::endl;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called " << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat " << name << " copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " destructor called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::increaseGrade()
{
	this->grade -= 1;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return(this->grade);
}

int	Bureaucrat::decreaseGrade()
{
	this->grade += 1;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return(this->grade);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (out);
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
