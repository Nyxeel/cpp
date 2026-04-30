/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/01 01:19:15 by pjelinek         ###   ########.fr       */
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
	Animal *cat = new Cat();
	cat->makeSound();			// MIAU
	std::cout << std::endl;

	Animal *dog = new Dog();
	dog->makeSound();			//WUFF
	std::cout << std::endl;

	Animal *animal = new Animal();
	animal->makeSound();		//makes animal sound
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete animal;

	//////////////////

	WrongAnimal *kitten = new WrongCat();
	kitten->makeSound();		//make wrong sound
	std::cout << std::endl;
	delete kitten;

	
	WrongCat wrongkitten;
	wrongkitten.makeSound();	//QUARK QUARK

}