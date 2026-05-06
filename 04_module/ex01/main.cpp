/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 23:51:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	Animal *animal[100];

	for (int i = 0; i < 100; i++)
	{
		std::cout << i << std::endl;
		if (i <= 49)
		{
			animal[i] = new Cat();
			std::cout << animal[i]->getType() << " " << i << ": ";
			animal[i]->makeSound();
			std::cout << animal[i]->brain;

		}
		if (i >= 50)
		{
			animal[i] = new Dog();
			std::cout << animal[i]->getType() << i << ": ";
			animal[i]->makeSound();
		}
	}
	for (int i = 0; i < 100; i++)
			delete animal[i];
}