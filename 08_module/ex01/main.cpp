/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:33:31 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/29 14:55:32 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

void	printNewline() {

	std::cout  << std::endl;
}

void	printContainer(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

	std::cout << " === CONTAINER === " << std::endl;

	int index = 0;
	for(; begin != end; begin++) {

		std::cout << "[" << index++ << "] | " << *begin << std::endl;
	}
	printNewline();
}


int	main(void)
{

	{
		// TEST 1
		std::cout << "\033[32mTest #1 : calc span when only 1 number is added (no span) \033[0m" << std::endl;

		Span span(5);
		try
		{
			span.addNumber(4);
			std::vector<int> container = span.getContainer();

			printContainer(container.begin(), container.end());
			std::cout << span.shortestSpan() << std::endl;
			std::cout << span.longestSpan() << std::endl;
		}
		catch (std::exception& e) {

			std::cout << e.what() << std::endl;
		}
	}

	printNewline();

	{
		// TEST 2
		std::cout << "\033[32mTest #2 : Add 5 numbers an print shortest(2) and longest(14) span \033[0m" << std::endl;

		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::vector<int> container = sp.getContainer();

			printContainer(container.begin(), container.end());

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	printNewline();

	{
		// TEST 3
		std::cout << "\033[32mTest #3 : Add 10 000 numbers from 0 - 9999\033[0m" << std::endl;

		Span sp = Span(10001);

		try {
			std::vector<int> vec;
			for (int i = 0; i < 10000; i++) {

				vec.push_back(i);
			}
			sp.addMultipleNumbers(vec.begin(), vec.end());

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	printNewline();

	{
		// TEST 4
		std::cout << "\033[32mTest #4 : Add randomized 10 000 numbers \033[0m" << std::endl;

		Span sp = Span(10001);

		srand(time(NULL));

		try {
			std::vector<int> vec;
			for (int i = 0; i < 10000; i++) {

				vec.push_back((rand() % 100000) - 50000);
			}

			sp.addMultipleNumbers(vec.begin(), vec.end());

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

	}

	printNewline();

	{
		// TEST 5
		std::cout << "\033[32mTest #5 : Add more numbers than capacity (MaxStoreException) \033[0m" << std::endl;

		Span sp = Span(3);

		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}