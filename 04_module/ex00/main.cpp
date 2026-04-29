/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/30 01:10:25 by pjelinek         ###   ########.fr       */
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
	cat->makeSound();
	std::cout << std::endl;

	Animal *dog = new Dog();
	dog->makeSound();
	std::cout << std::endl;

	Animal *animal = new Animal();
	animal->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;

	//////////////////

	WrongAnimal *kitten = new WrongCat();
	kitten->makeSound();
	std::cout << std::endl;

	WrongCat wrongkitten;
	wrongkitten.makeSound();


}