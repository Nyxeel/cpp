/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:03:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/01 01:13:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a(5.5f);
	Fixed b(2);

	std::cout << std::boolalpha;
	std::cout << "----- Values -----" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "\n----- Comparison operators -----" << std::endl;
	std::cout << "a > b  = " << (a > b) << std::endl;
	std::cout << "a < b  = " << (a < b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;

	std::cout << "\n----- Arithmetic operators -----" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	std::cout << "\n----- Increment / Decrement -----" << std::endl;
	Fixed c;

	std::cout << "c = " << c << std::endl;

	std::cout << "++c = " << ++c << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "--c = " << --c << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "c-- = " << c-- << std::endl;
	std::cout << "c = " << c << std::endl;


	std::cout << "\n----- min / max -----" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	std::cout << "\n----- const min / max -----" << std::endl;
	const Fixed d(42.42f);
	const Fixed e(21.21f);

	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "min(d, e) = " << Fixed::min(d, e) << std::endl;
	std::cout << "max(d, e) = " << Fixed::max(d, e) << std::endl;

	return 0;
}