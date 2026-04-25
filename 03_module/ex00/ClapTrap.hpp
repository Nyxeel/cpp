/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:37:19 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/25 17:05:25 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
/* #ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP */

#include <string>

class ClapTrap
{

	private:
		std::string name;
		int			hitPoints;		// 10
		int			energyPoints;	// 10
		int			attackDamage;	// 0

	public:

	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};



/* #endif CLAPTRAP_HPP */ 