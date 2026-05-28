/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 23:51:26 by pjelinek         ###   ########.fr       */
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
		Bureaucrat john("John", 150);
		std::cout << john;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();


	try {
		Bureaucrat john("JohnLow", 151);
		std::cout << john;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();


	try {
		Bureaucrat john("JohnHigh", 1);
		std::cout << john;
		john.increaseGrade();
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();


	try {
		Bureaucrat john("JohnTooHigh", 0);
		std::cout << john;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();


	try {
		Bureaucrat john("JohnTooLow", 151);
		std::cout << john;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printNewline();



	try {
		Bureaucrat john("John", 100);
		Bureaucrat peter("Peter", 2);

		peter = john;
		std::cout << "Copy assignment Test" << std::endl;
		std::cout << peter;

	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

		printNewline();



	try {
		Bureaucrat john("John", 100);
		Bureaucrat peter(john);
		std::cout << "Copy constructor Test" << std::endl;

		std::cout << peter;

	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

		printNewline();


	try {
		Bureaucrat john("JohnIntMin", -2147483648);
		std::cout << john;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

}