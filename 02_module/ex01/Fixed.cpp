/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:44:05 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 17:45:40 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <cstring>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPointNb = 0;
}

Fixed::Fixed (const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNb = nb << fractBits;
}

Fixed::Fixed (const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointNb = roundf(nb * (1 << fractBits));
}


Fixed::Fixed(const Fixed &other)	:
	fixedPointNb(other.fixedPointNb)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &other)
		fixedPointNb = other.fixedPointNb;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointNb);
}

void Fixed::setRawBits(const int raw)
{
	fixedPointNb = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float> (fixedPointNb) / (1 << fractBits));
}

int Fixed::toInt() const
{
	return (fixedPointNb / (1 << fractBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}

