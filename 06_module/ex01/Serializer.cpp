/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 00:58:28 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 17:31:09 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer(){
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other){
	(void) other;
	std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer&	Serializer::operator=(const Serializer &other){
	(void) other;
	std::cout << "Serializer copy assignment operator called" << std::endl;
	return (*this);
}

Serializer::~Serializer(){
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t 	Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}
