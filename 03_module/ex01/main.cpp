/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/01 00:09:12 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(5);
	a.attack("B");
	b.takeDamage(10);

	// B is dead and cant attack or repair or take damage
	b.attack("A");
	b.beRepaired(5);
	b.takeDamage(0);


	///////////////////////////////

	ScavTrap c("C");

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	a.attack("C");
	c.takeDamage(1);

	//A has no energy points left
	a.attack("C");






	return (0);
}