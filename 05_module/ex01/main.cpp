/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/30 21:03:18 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

void printNewline(){

	std::cout << std::endl;
}

void bureaucrateTests()
{

	try {
		std::cout << "\033[32mBureaucrat valid lowest grade\033[0m" << std::endl;
		Bureaucrat john("John", 150);
		std::cout << john << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat valid highest grade\033[0m" << std::endl;
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat grade too high constructor\033[0m" << std::endl;
		Bureaucrat invalid("InvalidHigh", 0);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat grade too low constructor\033[0m" << std::endl;
		Bureaucrat invalid("InvalidLow", 151);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat increment grade success\033[0m" << std::endl;
		Bureaucrat john("John", 2);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat increment grade too high\033[0m" << std::endl;
		Bureaucrat john("John", 1);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat decrement grade success\033[0m" << std::endl;
		Bureaucrat john("John", 149);
		std::cout << john << std::endl;
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat decrement grade too low\033[0m" << std::endl;
		Bureaucrat john("John", 150);
		std::cout << john << std::endl;
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat copy constructor\033[0m" << std::endl;
		Bureaucrat john("John", 42);
		Bureaucrat copy(john);
		std::cout << john << std::endl;
		std::cout << copy << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mBureaucrat assignment operator\033[0m" << std::endl;
		Bureaucrat john("John", 42);
		Bureaucrat bob("Bob", 100);
		std::cout << john << std::endl;
		std::cout << bob << std::endl;
		bob = john;
		std::cout << bob << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();
}


void	formTests()
{
	try {
		std::cout << "\033[32mForm parameter constructor valid\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm copy constructor unsigned form\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		Form copy(letter);

		std::cout << letter;
		std::cout << copy;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm copy constructor signed form\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 100);

		john.signForm(letter);

		Form copy(letter);

		std::cout << letter;
		std::cout << copy;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm assignment operator unsigned form\033[0m" << std::endl;
		Form source("source", 100, 50);
		Form target("target", 120, 80);

		std::cout << source;
		std::cout << target;

		target = source;

		std::cout << source;
		std::cout << target;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm assignment operator signed form\033[0m" << std::endl;
		Form source("source", 100, 50);
		Form target("target", 120, 80);
		Bureaucrat john("John", 100);

		john.signForm(source);

		std::cout << source;
		std::cout << target;

		target = source;

		std::cout << source;
		std::cout << target;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm valid high requirements\033[0m" << std::endl;
		Form letter("letter", 1, 1);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm valid low requirements\033[0m" << std::endl;
		Form letter("letter", 150, 150);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm sign grade too high\033[0m" << std::endl;
		Form letter("letter", -1, 50);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm sign grade too low\033[0m" << std::endl;
		Form letter("letter", 151, 50);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm exec grade too high\033[0m" << std::endl;
		Form letter("letter", 50, 0);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm exec grade too low\033[0m" << std::endl;
		Form letter("letter", 50, 151);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm sign failed grade too low\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 101);

		std::cout << john;
		std::cout << letter;
		john.signForm(letter);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm sign success exact grade\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 100);

		std::cout << john;
		std::cout << letter;
		john.signForm(letter);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm sign success better grade\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		Bureaucrat boss("Boss", 1);

		std::cout << boss;
		std::cout << letter;
		boss.signForm(letter);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();

	try {
		std::cout << "\033[32mForm double sign\033[0m" << std::endl;
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 100);

		std::cout << john;
		std::cout << letter;
		john.signForm(letter);
		john.signForm(letter);
		std::cout << letter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printNewline();
}

int	main(void)
{
	bureaucrateTests();
	formTests();
}