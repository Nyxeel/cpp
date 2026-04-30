/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/29 21:39:22 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap a("BB");

	std::cout << "a "<< std::endl;


	std::cout << "Who am I??" << std::endl;
	a.whoAmI();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "c"<< std::endl;




	DiamondTrap c;
	c = a;
	c.whoAmI(); // BB and BB_clap_name from DiamondTrap a;

	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "dora"<< std::endl;

	DiamondTrap dora(c);
	dora.whoAmI();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "e"<< std::endl;

	DiamondTrap e = a;
	e.whoAmI();
	//std::cout << "DiamondTrap Hitpoints: " << a.hitPoints





	return (0);
}