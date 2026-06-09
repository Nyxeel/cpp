/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:17:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 23:48:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called " << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const char* ShrubberyCreationForm::OpenCreateFileFailed::what() const throw()
{
	return ("cannot open/create out file.");
}

std::string	getAsciiTree()
{
	return
	"              /\\\n"
	"             /**\\\n"
	"            /****\\\n"
	"           /******\\\n"
	"          /********\\\n"
	"         /**********\\\n"
	"        /************\\\n"
	"       /**************\\\n"
	"      /****************\\\n"
	"     /******************\\\n"
	"            ||||\n"
	"            ||||\n"
	"            ||||\n";
}
void 		ShrubberyCreationForm::executeAction() const
{
	std::string outFile = target + "_shrubbery";
	std::ofstream file(outFile.c_str());
	if (!file)
		throw ShrubberyCreationForm::OpenCreateFileFailed();
	file << getAsciiTree();
}


