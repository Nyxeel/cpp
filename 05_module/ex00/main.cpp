/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:45 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/28 22:41:18 by pjelinek         ###   ########.fr       */
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

}