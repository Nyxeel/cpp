/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/19 19:38:03 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	// 1) guardGate()
	ScavTrap gate("Gate");
	gate.guardGate();

	// 2) Copy-Konstruktor
	ScavTrap original("Original");
	ScavTrap copyConstructed(original); // copy constructor

	// 3) Copy-Assignment
	ScavTrap assigned("Assigned");
	assigned = original; // operator=


	ScavTrap tired("Tired");
	for (int i = 0; i < 50; ++i)
	    tired.attack("Dummy");
	tired.attack("Dummy"); 			// not enough energy

	original.takeDamage(30);
	copyConstructed.beRepaired(10);
	assigned.beRepaired(10);

	return (0);
}