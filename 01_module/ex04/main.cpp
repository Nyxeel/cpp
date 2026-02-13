/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:33:10 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/13 03:57:01 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.h"
#include "iostream"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 4)
	{
		std::cout << "Error\nEnter 3 exact arguments!" << std::endl;
		return (0);
	}
	if (!av[1] || !av[2] || !av[3])
		return (1);

	/* READ from file to input */
	std::ifstream input(av[1]);
	if (!input)
	{
		std::cout << "Error\nCannot open file" << std::endl;
		return (1);
	}

	replaceInput(input, av[1], av[2], av[3]);

	return (0);
}