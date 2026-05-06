/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:44:05 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/06 17:57:43 by pjelinek         ###   ########.fr       */
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
	std::cout << "Copy assignment operator called" << std::endl;
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
	return (static_cast<int> (fixedPointNb) / (1 << fractBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (fixedPointNb == other.fixedPointNb);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (fixedPointNb <= other.fixedPointNb);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (fixedPointNb >= other.fixedPointNb);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (fixedPointNb > other.fixedPointNb);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (fixedPointNb < other.fixedPointNb);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (fixedPointNb != other.fixedPointNb);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed subtract;

	subtract.setRawBits(fixedPointNb - other.fixedPointNb);
	return (subtract);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed addition;

	addition.setRawBits(fixedPointNb + other.fixedPointNb);
	return (addition);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed multi;

	multi.setRawBits((static_cast<float> (fixedPointNb) * static_cast<float> (other.fixedPointNb)) / (1 << fractBits));
	return (multi);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed division;

	division.setRawBits((static_cast<float> (fixedPointNb) / static_cast<float> (other.fixedPointNb)) * (1 << fractBits));
	return (division);
}

Fixed& Fixed::operator++()
{
	this->fixedPointNb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->fixedPointNb++;
	return (old);
}

Fixed& Fixed::operator--()
{
	this->fixedPointNb--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	this->fixedPointNb--;
	return (old);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}