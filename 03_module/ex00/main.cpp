/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/19 17:15:25 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(5);
	a.attack("B");
	b.takeDamage(10);

	// B is dead and cant attack or repair or take damage
	b.attack("A");
	b.beRepaired(5);
	b.takeDamage(0);


	/////////////////////////////////////////////////////////////////////

	ClapTrap c("C");

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

	/////////////////////////////////////////////////////////////////
	//A has no energy points left
	a.attack("C");
	a.beRepaired(5);



	////////////////////////////////////////////////////////////////
	// Copy constructor and assignment operator test
	ClapTrap test("Test");
	ClapTrap d(test);
	ClapTrap e;
	e = test;

	test.takeDamage(1);		// 9 HP left
	d.beRepaired(5);		///15 HP lef -> Different Instances
	e.beRepaired(5);		///15 HP left -> Different Instances

	return (0);
}