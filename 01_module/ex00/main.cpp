/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/01 01:28:36 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>


int main(void)
{
	/* Zombie Chuck */
	Zombie *zombie1;

	zombie1 = newZombie("Chuck");
	zombie1->announce();
	delete (zombie1);

	/* Zombie Jeff */
	randomChump("Jeff");

	return (0);
}
