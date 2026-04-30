/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/01 01:27:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	/* Zombie Horde */
	int N = 10;
	Zombie *Horde = zombieHorde(N, "WALKERS");

	for (int i = 0; i < N; i++)
	{
		Horde[i].announce();
	}
	delete[] (Horde);
	
	return (0);
}
