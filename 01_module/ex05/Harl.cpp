/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:26:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 19:20:57 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	std::cout << "Harl constructed" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destructed" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger ";
	std::cout << "I really do!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years, whereas you started ";
	std::cout << "working here just last month." << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*fn[4]) () = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string action[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (action[i] == level)
		{
			(this->*fn[i]) ();
			return ;
		}
	}
	std::cout << "Level not found!" << std::endl;
}
