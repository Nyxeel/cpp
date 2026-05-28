/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 23:48:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(const std::string name, int grade) :
	name(name)
{
	if (grade > 150)
		throw Form::GradeTooLow();
	if (grade < 1)
		throw Form::GradeTooHigh();
	std::cout << "Form " << name << " constructor called " << std::endl;
	this->grade = grade;
}

Form::Form(const Form &other) :
	name(other.name), grade(other.grade)
{
	std::cout << "Form copy constructor called " << std::endl;
}

Form& Form::operator=(const Form &other)
{
	std::cout << "Form " << name << " copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		grade = other.grade;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

int	Form::getGrade() const
{
	return this->grade;
}

const std::string Form::getName() const
{
	return (this->name);
}

int	Form::increaseGrade()
{
	if (this->grade - 1 < 1)
		throw Form::GradeTooHighException();
	this->grade -= 1;
	return(this->grade);
}

int	Form::decreaseGrade()
{
	if (this->grade + 1 > 150)
		throw Form::GradeTooLowException();
	this->grade += 1;
	return(this->grade);
}

std::ostream& operator<<(std::ostream &out, const Form &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (out);
}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
