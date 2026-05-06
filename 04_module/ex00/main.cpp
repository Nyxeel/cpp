/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 20:09:44 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " Type " << std::endl;
	std::cout << i->getType() << " Type " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete	j;
	delete	i;
	delete	meta;

	std::cout << std::endl;

	////////////////////////

	Animal *cat = new Cat();
	std::cout << cat->getType() << " Type ";
	cat->makeSound();			// MIAU
	std::cout << std::endl;

	Animal *dog = new Dog();
	std::cout << dog->getType() << " Type ";
	dog->makeSound();			//WUFF
	std::cout << std::endl;

	Animal *animal = new Animal();
	std::cout << animal->getType() << " Type ";
	animal->makeSound();		//makes animal sound
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete animal;

	//////////////////

	WrongAnimal *kitten = new WrongCat();
	std::cout << kitten->getType() << " Type ";
	kitten->makeSound();		//make wrong sound
	std::cout << std::endl;
	delete kitten;


	WrongCat wrongKitten;
	std::cout << wrongKitten.getType() << " Type ";
	wrongKitten.makeSound();	//QUARK QUARK
}