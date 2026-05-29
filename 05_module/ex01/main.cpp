/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/29 03:47:12 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void printNewline(){

	std::cout << std::endl;
}


void bureaucrateTests()
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


int	main(void)
{

	// bureaucrateTests();
	// formTests();

	try {
		Form letter("letter", -1, 50);  // relevant with negativ numbers??
		std::cout << letter;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();

	// Not sign Form
	try {
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 101);
		std::cout << john;
		std::cout << letter;
		john.signForm(letter);
		std::cout << letter;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();


	//Sign Form
	try {
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 100);
		std::cout << john;
		std::cout << letter;
		john.signForm(letter);
		std::cout << letter;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();



	//Double Sign Form
	try {
		Form letter("letter", 100, 50);
		Bureaucrat john("John", 100);
		std::cout << john;
		std::cout << letter;
		john.signForm(letter);
		john.signForm(letter); //double error beauce form is already signed
		std::cout << letter;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();

}