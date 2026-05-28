/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/19 19:08:19 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{

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


		/////////////////////////////////////////////////////////////////

		// 1) guardGate()
		ScavTrap gate("Gate");
		gate.guardGate();

		// 2) Copy-Konstruktor
		ScavTrap original("Original");
		ScavTrap copyConstructed(original); // copy ctor

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

	}

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


		std::cout << "Konstruktion: ClapTrap";
	    DiamondTrap hero("Bob");

	    std::cout << "\n=== whoAmI ===\n";
	    hero.whoAmI();
	    // DiamondTrap name: Bob
	    // ClapTrap name: Bob_clap_name

	    std::cout << "\nattack() uses ScavTrap\n";
	    hero.attack("TrainingDummy");

	    std::cout << "guardGate() and highFivesGuys()\n";
	    hero.guardGate();
	    hero.highFivesGuys();

	    std::cout << "HP=100\n";
	    hero.takeDamage(40);   // 100 -> 60
	    hero.beRepaired(10);   // 60 -> 70 (Energy -1)

	    std::cout << "Energy=50 multi attack check\n";
	    DiamondTrap stamina("Stamina");
	    for (int i = 0; i < 50; ++i)
	        stamina.attack("Wall");
	    stamina.attack("Wall");
	    // last attack "not enough energy"

	    std::cout << "Copy Constructor\n";
	    DiamondTrap clone(hero);
	    clone.whoAmI();
	    clone.attack("CloneTarget");

	    std::cout << "Copy Assignment\n";
	    DiamondTrap assigned("TempName");
	    assigned = hero;
	    assigned.whoAmI();
	    assigned.attack("AssignedTarget");

	    std::cout << "Destruction: ClapTrap once per DiamondTrap\n";

		std::cout << std::endl;

	}

	return (0);
}