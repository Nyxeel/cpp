/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:33:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/09 20:16:42 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#pragma once

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	~Zombie();

	void setName( std::string name );
	void announce( void );
};

Zombie* zombieHorde( int N, std::string name );