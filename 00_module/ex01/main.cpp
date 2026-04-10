/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:06:29 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/10 13:05:26 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "phonebook.hpp"


int main(void)
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "Welcome to the PhoneBook!" << "\n";
	while (1)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT!" << "\n";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		else if (input == "EXIT")\
			break;
	}
	return (0);
}
