/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:57:38 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/17 19:44:00 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <exception>
#include <iostream>

void	printError(std::string str) {

	std::cerr << str << std::endl;
}

int	main(int ac, char **av)
{
	try {
		if (ac < 2)
			throw std::runtime_error("Error");
		PmergeMe container(av, ac);
		container.runSort();

	}
	catch(std::exception& e) {
		printError(e.what());
	}

	return (0);
}