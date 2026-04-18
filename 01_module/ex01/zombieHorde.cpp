/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:49:57 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/11 19:31:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(name);
	}
	return Horde;
}
