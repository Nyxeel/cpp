/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:38:33 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 15:15:28 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class	AAnimal
{
	protected:
		std::string  type;

	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal& operator=(const AAnimal &other);
		virtual ~AAnimal() = 0;

		virtual void makeSound() const;
		virtual const std::string getType() const;
};

#endif