/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:33:31 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:10 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

void print(std::string str) {

	std::cout << str <<std::endl;
}

void printError(std::string str) {

	std::cerr << str <<std::endl;
}

int main(int ac, char const *av[])
{
	try {

		if (ac < 2 || ac > 2) {
			throw std::runtime_error("Error: could not open file");
			return (1);
		}
		BitcoinExchange btc;
		btc.processData(av[1]);
	}
	catch(std::exception &e) {
		printError(e.what());
	}
	(void) av;

	return 0;
}
