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
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string name, int signGrade, int execGrade) :
	name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false)
{
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form " << name << " constructor called " << std::endl;
}

Form::Form(const Form &other) :
	name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned)
{
	std::cout << "Form " << name << " copy constructor called " << std::endl;
}

Form& Form::operator=(const Form &other)
{
	std::cout << "Form " << name << " copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		signGrade = other.signGrade;
		execGrade = other.execGrade;
		isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSignedStatus() const
{
	return (this->isSigned);
}

int	Form::getSignGrade() const
{
	return this->signGrade;
}

int	Form::getExecGrade() const
{
	return this->execGrade;
}

std::ostream& operator<<(std::ostream &out, const Form &other)
{
	out << other.getName() << ", signing grade " << other.getSignGrade()
	<< ", execution grade " << other.getExecGrade()	<< ", sign status: ";
	if (other.getSignedStatus())
		out << "signed" << "." << std::endl;
	else
		out << "not signed" << "." << std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high to sign the Form");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low to sign the Form");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("is already signed.");
}

void	Form::beSigned(const Bureaucrat &other)
{
	if(other.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	if (getSignedStatus())
		throw Form::FormAlreadySignedException();
	isSigned = true;
}
