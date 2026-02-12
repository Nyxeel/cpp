/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/12 03:43:48 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
