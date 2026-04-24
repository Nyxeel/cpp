/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/24 20:25:06 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Ben");
	ClapTrap b("Lukas");

	a.attack("Lukas");
	b.takeDamage(2);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");
	b.takeDamage(1);
	a.attack("Lukas");

	// No energy points left



	return (0);
}