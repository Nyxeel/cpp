/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/30 21:44:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>

void printNewline(){

	std::cout << std::endl;
}

void 	shrubberyTests()
{
	try {
		std::cout << "\033[32mShrubbery execute without signature\033[0m" << std::endl;
		ShrubberyCreationForm form("garden");
		Bureaucrat executor("Executor", 1);

		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery sign failed grade too low\033[0m" << std::endl;
		ShrubberyCreationForm form("garden");
		Bureaucrat john("John", 146);

		std::cout << john;
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery execute failed grade too low\033[0m" << std::endl;
		ShrubberyCreationForm form("garden");
		Bureaucrat signer("Signer", 145);
		Bureaucrat executor("Executor", 138);

		signer.signForm(form);
		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery execute success exact grades\033[0m" << std::endl;
		ShrubberyCreationForm form("garden");
		Bureaucrat signer("Signer", 145);
		Bureaucrat executor("Executor", 137);

		signer.signForm(form);
		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery executeForm success\033[0m" << std::endl;
		ShrubberyCreationForm form("home");
		Bureaucrat john("John", 1);

		john.signForm(form);
		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery executeForm failed unsigned\033[0m" << std::endl;
		ShrubberyCreationForm form("park");
		Bureaucrat john("John", 1);

		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery polymorphic execute through AForm reference\033[0m" << std::endl;
		ShrubberyCreationForm shrubbery("forest");
		AForm& form = shrubbery;
		Bureaucrat john("John", 1);

		john.signForm(form);
		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mShrubbery copy constructor keeps target\033[0m" << std::endl;
		ShrubberyCreationForm original("copytest");
		Bureaucrat john("John", 1);

		john.signForm(original);

		ShrubberyCreationForm copy(original);
		std::cout << copy;
		john.executeForm(copy);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

}

void	presidentialTests()
{
	try {
		std::cout << "\033[32mPresidential execute without signature\033[0m" << std::endl;
		PresidentialPardonForm form("Arthur");
		Bureaucrat executor("Executor", 1);

		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential sign failed grade too low\033[0m" << std::endl;
		PresidentialPardonForm form("Arthur");
		Bureaucrat john("John", 26);

		std::cout << john;
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential execute failed grade too low\033[0m" << std::endl;
		PresidentialPardonForm form("Arthur");
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 6);

		signer.signForm(form);
		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential execute success exact grades\033[0m" << std::endl;
		PresidentialPardonForm form("Arthur");
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 5);

		signer.signForm(form);
		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential executeForm success\033[0m" << std::endl;
		PresidentialPardonForm form("Ford");
		Bureaucrat john("John", 1);

		john.signForm(form);
		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential executeForm failed unsigned\033[0m" << std::endl;
		PresidentialPardonForm form("Trillian");
		Bureaucrat john("John", 1);

		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential polymorphic execute through AForm reference\033[0m" << std::endl;
		PresidentialPardonForm presidential("Marvin");
		AForm& form = presidential;
		Bureaucrat john("John", 1);

		john.signForm(form);
		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mPresidential copy constructor keeps target\033[0m" << std::endl;
		PresidentialPardonForm original("Zaphod");
		Bureaucrat john("John", 1);

		john.signForm(original);

		PresidentialPardonForm copy(original);
		std::cout << copy;
		john.executeForm(copy);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();
}

void	robotomizeTests()
{

	try {
		std::cout << "\033[32mRobotomy executeForm failed unsigned\033[0m" << std::endl;
		RobotomyRequestForm form("Bender");
		Bureaucrat john("John", 1);

		std::cout << form;
		std::cout << john;
		john.executeForm(form);
		std::cout << form;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy sign failed grade too low\033[0m" << std::endl;
		RobotomyRequestForm form("Bender");
		Bureaucrat john("John", 73);

		std::cout << form;
		std::cout << john;
		john.signForm(form);
		std::cout << form;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy executeForm failed grade too low\033[0m" << std::endl;
		RobotomyRequestForm form("Bender");
		Bureaucrat signer("Signer", 72);
		Bureaucrat executor("Executor", 46);

		std::cout << form;
		std::cout << signer;
		signer.signForm(form);
		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy executeForm success exact grades\033[0m" << std::endl;
		RobotomyRequestForm form("Bender");
		Bureaucrat signer("Signer", 72);
		Bureaucrat executor("Executor", 45);

		std::cout << form;
		std::cout << signer;
		signer.signForm(form);
		std::cout << form;
		std::cout << executor;
		executor.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy executeForm success better grade\033[0m" << std::endl;
		RobotomyRequestForm form("Marvin");
		Bureaucrat john("John", 1);

		std::cout << form;
		std::cout << john;
		john.signForm(form);
		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy executeForm random repeated\033[0m" << std::endl;
		RobotomyRequestForm form("R2D2");
		Bureaucrat john("John", 1);

		std::cout << form;
		std::cout << john;
		john.signForm(form);
		std::cout << form;

		john.executeForm(form);
		john.executeForm(form);
		john.executeForm(form);
		john.executeForm(form);
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy polymorphic executeForm through AForm reference\033[0m" << std::endl;
		RobotomyRequestForm robotomy("Wall-E");
		AForm& form = robotomy;
		Bureaucrat john("John", 1);

		std::cout << form;
		std::cout << john;
		john.signForm(form);
		std::cout << form;
		john.executeForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mRobotomy copy constructor keeps target\033[0m" << std::endl;
		RobotomyRequestForm original("CopyBot");
		Bureaucrat john("John", 1);

		john.signForm(original);

		RobotomyRequestForm copy(original);
		std::cout << copy;
		john.executeForm(copy);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();
}

int	main(void)
{
	srand (time(NULL));

	//TESTS
	shrubberyTests();
	presidentialTests();
	robotomizeTests();
}