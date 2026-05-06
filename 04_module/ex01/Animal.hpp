/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:38:33 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 22:33:55 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal
{
	protected:
		std::string  type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const;
		virtual const std::string getType() const;
};

#endif