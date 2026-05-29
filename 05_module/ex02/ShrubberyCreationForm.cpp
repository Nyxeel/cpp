/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 23:48:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string name, const int signGrade, const int execGrade) :
	name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm " << name << " constructor called " << std::endl;
}

AForm::AForm(const AForm &other) :
	name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned)
{
	std::cout << "Form " << name << " copy constructor called " << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	std::cout << "Form " << name << " copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSignedStatus() const
{
	return (this->isSigned);
}

int	AForm::getSignGrade() const
{
	return signGrade;
}

int	AForm::getExecGrade() const
{
	return execGrade;
}

std::ostream& operator<<(std::ostream &out, const AForm &other)
{
	out << other.getName() << ", signing grade " << other.getSignGrade()
	<< ", execution grade " << other.getExecGrade()	<< ", sign status: ";
	if (other.getSignedStatus())
		out << "signed" << "." << std::endl;
	else
		out << "not signed" << "." << std::endl;
	return (out);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high to sign the AForm");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low to sign the AForm");
}

/* const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("is already signed.");
} */

void	AForm::beSigned(const Bureaucrat &other)
{
	if(other.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
/* 	if (getSignedStatus())
		throw AForm::AFormAlreadySignedException(); */
	isSigned = true;
}
