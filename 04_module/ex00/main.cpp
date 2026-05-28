/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/22 20:47:10 by pjelinek         ###   ########.fr       */
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
	std::cout << "Test 1: subject example" << std::endl;
	printNewline();

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " Type " << std::endl; //Dog
	std::cout << i->getType() << " Type " << std::endl;	//Cat

	printNewline();
	printNewline();

	i->makeSound(); 	// Expected: Cat sound
	j->makeSound(); 	// Expected: Dog sound
	meta->makeSound();	// Expected: Animal sound

	printNewline();
	printNewline();

	delete	i;
	delete	j;
	delete	meta;


	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	printNewline();

	std::cout << "Test 2: Cat / Dog / Animal example" << std::endl;
	printNewline();

	Animal *cat = new Cat();
	std::cout << cat->getType() << " Type "; 	//Cat
	cat->makeSound();							// Expected: Cat sound

	printNewline();
	printNewline();

	Animal *dog = new Dog();
	std::cout << dog->getType() << " Type "; 	//Dog
	dog->makeSound();							// Expected: Dog sound

	printNewline();
	printNewline();

	Animal *animal = new Animal();
	std::cout << animal->getType() << " Type ";
	animal->makeSound();						// Expected: Animal sound

	printNewline();
	printNewline();

	delete dog;
	delete cat;
	delete animal;
	// Expected destructor


	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	printNewline();


	std::cout << "Test 3: WrongAnimal no polymorphism example" << std::endl;
	printNewline();

	const WrongAnimal *kitten = new WrongCat();
	std::cout << kitten->getType() << " Type ";
	kitten->makeSound();		// Expected: WrongAnimal sound

	printNewline();
	printNewline();

	delete kitten;

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	printNewline();

	std::cout << "Test 4: Direct WrongCat call" << std::endl;
	printNewline();

	WrongCat wrongKitten;
	std::cout << wrongKitten.getType() << " Type ";	// WrongCat
	wrongKitten.makeSound();						// Expected: WrongCat sound
	printNewline();
	printNewline();


	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	std::cout << "Test 5: Copy constructor test" << std::endl;
	printNewline();

	Cat originalCat;
	Cat copiedCat(originalCat);
	std::cout << copiedCat.getType() << " Type ";
	copiedCat.makeSound();							// Expected: Cat sound
	printNewline();
	printNewline();


	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	std::cout << "Test 6: Copy assignment test" << std::endl;
	printNewline();

	Dog originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << assignedDog.getType() << " Type ";
	assignedDog.makeSound();						// Expected: Dog sound

	printNewline();
	printNewline();

	return (0);
}