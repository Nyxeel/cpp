/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 15:08:46 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	printNewline()
{
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "\033[32mTest 1: subject example\033[0m" << std::endl;

	printNewline();

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " Type " << std::endl; //Dog
	std::cout << i->getType() << " Type " << std::endl;	//Cat

	printNewline();

	i->makeSound(); 	// Expected: Cat sound
	j->makeSound(); 	// Expected: Dog sound
	meta->makeSound();	// Expected: Animal sound

	printNewline();

	delete	i;
	delete	j;
	delete	meta;
	printNewline();



	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	printNewline();

	std::cout << "\033[32mTest 2: Cat / Dog / Animal example\033[0m" << std::endl;

	printNewline();

	Animal *cat = new Cat();
	std::cout << cat->getType() << " Type "; 	//Cat
	cat->makeSound();							// Expected: Cat sound

	printNewline();

	Animal *dog = new Dog();
	std::cout << dog->getType() << " Type "; 	//Dog
	dog->makeSound();							// Expected: Dog sound

	printNewline();

	Animal *animal = new Animal();
	std::cout << animal->getType() << " Type ";
	animal->makeSound();						// Expected: Animal sound

	printNewline();

	delete dog;
	delete cat;
	delete animal;

	// Expected destructor
	printNewline();



	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	printNewline();

	std::cout << "\033[32mTest 3: WrongAnimal no polymorphism example\033[0m" << std::endl;

	printNewline();

	const WrongAnimal *kitten = new WrongCat();
	std::cout << kitten->getType() << " Type ";
	kitten->makeSound();		// Expected: WrongAnimal sound

	printNewline();

	delete kitten;
	printNewline();

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	printNewline();

	std::cout << "\033[32mTest 4: Direct WrongCat call\033[0m" << std::endl;
	printNewline();
	{
		WrongCat wrongKitten;
		std::cout << wrongKitten.getType() << " Type ";	// WrongCat
		wrongKitten.makeSound();						// Expected: WrongCat sound
		printNewline();

	}
	printNewline();
	printNewline();

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	std::cout << "\033[32mTest 5: Copy constructor test\033[0m" << std::endl;
	printNewline();

	{
		Cat originalCat;
		Cat copiedCat(originalCat);
		std::cout << copiedCat.getType() << " Type ";
		copiedCat.makeSound();							// Expected: Cat sound
		printNewline();
	}
	printNewline();
	printNewline();


	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	std::cout << "\033[32mTest 6: Copy assignment test\033[0m" << std::endl;

	printNewline();

	Dog originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << assignedDog.getType() << " Type ";
	assignedDog.makeSound();						// Expected: Dog sound

	printNewline();

	return (0);
}