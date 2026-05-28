/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/19 20:23:51 by pjelinek         ###   ########.fr       */
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

	// Test 2
	Animal* zoo[10];
	for (int k = 0; k < 10; k++)
	{
	    if (k < 5)
	        zoo[k] = new Cat();
	    else
	        zoo[k] = new Dog();
	    std::cout << zoo[k]->getType() << " #" << k << ": ";
	    zoo[k]->makeSound();	// Expected Cat for 0-4, Dog for 5-9
	}
	for (int k = 0; k < 10; k++)
	    delete zoo[k];		// Expected no leak, no crash
	std::cout << std::endl;

	// Test 3
	Cat originalCat;
	Cat copiedCat(originalCat);
	std::cout << copiedCat.getType() << " Type ";
	copiedCat.makeSound();		// Expected: Cat sound
	std::cout << std::endl;
	// Expected: both objects destroy cleanly (deep copy, no double free)

	// Test 4
	Dog originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << assignedDog.getType() << " Type ";
	assignedDog.makeSound();	// Expected: Dog sound
	std::cout << std::endl;
	// Expected: both objects destroy cleanly (deep copy, no double free)

	return 0;
}