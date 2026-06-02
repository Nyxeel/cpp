/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 15:14:00 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void	printNewline()
{
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "\033[32mTest 1: Create 10 animals (0-4 Cats | 5-9 Dogs)\033[0m" << std::endl;

	Animal *animal[10];

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
		if (i <= 4)
		{
			animal[i] = new Cat();
			std::cout << animal[i]->getType() << " " << i << ": ";
			animal[i]->makeSound();
		}
		if (i >= 5)
		{
			animal[i] = new Dog();
			std::cout << animal[i]->getType() << i << ": ";
			animal[i]->makeSound();
		}
	}
	printNewline();
	for (int i = 0; i < 10; i++){

			delete animal[i];
	}
	printNewline();
	printNewline();

	std::cout << "\033[32mTest 2: Create 10 animals (0-4 Cats | 5-9 Dogs)\033[0m" << std::endl;
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
	printNewline();
	for (int k = 0; k < 10; k++)
	    delete zoo[k];		// Expected no leak, no crash

	printNewline();
	printNewline();

	std::cout << "\033[32mTest 3: Cat copy assignment operator\033[0m" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat);
	std::cout << copiedCat.getType() << " Type ";
	copiedCat.makeSound();		// Expected: Cat sound

	// Expected: both objects destroy cleanly (deep copy, no double free)
	printNewline();
	printNewline();

	std::cout << "\033[32mTest 4: Dog copy assignment operator\033[0m" << std::endl;
	Dog originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << assignedDog.getType() << " Type ";
	assignedDog.makeSound();	// Expected: Dog sound

	// Expected: both objects destroy cleanly (deep copy, no double free)

	return 0;
}