/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/30 20:53:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void printNewline(){

	std::cout << std::endl;
}

int	main(void)
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