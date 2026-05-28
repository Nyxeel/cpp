/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:37:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/22 20:16:02 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " Type " << std::endl;
	std::cout << i->getType() << " Type " << std::endl;
	std::cout << std::endl;

	////////////////////////////////////////i->makeSound(); // Expected: Cat sound


	return 0;
}///////////////////////