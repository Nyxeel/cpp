/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:57:38 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/16 15:02:15 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>


void	printError(std::string str) {

	std::cerr << str << std::endl;
}

int	main(int ac, char *av[])
{
	try {
		if (ac != 2)
			throw std::runtime_error("ERROR: enter exactly 2 arguments");
		RPN rpn(av[1]);


	}
	catch(std::exception& e) {
		printError(e.what());
	}

	return (0);
}