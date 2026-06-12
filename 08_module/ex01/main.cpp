/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:33:31 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/12 13:53:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

void	printNewline() {

	std::cout  << std::endl;
}

template <typename T>
void	printSequenceContainer(const T& container){


	typename T::const_iterator begin = container.begin();
	typename T::const_iterator end = container.end();

	std::cout << " === CONTAINER === " << std::endl;

	int index = 0;
	for(; begin != end; begin++) {

		std::cout << "[" << index++ << "] | " << *begin << std::endl;
	}
	printNewline();
}

template <typename T>
void	printSequenceContainer(T& container){


	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	std::cout << " === CONTAINER === " << std::endl;

	int index = 0;
	for(; begin != end; begin++) {

		std::cout << "[" << index++ << "] | " << *begin << std::endl;
	}
	printNewline();
}

void	vectorTests() {

	//std::vector<int>::reverse_iterator rev = a.rbegin();

	std::cout << "\033[32mTest #1 : Try to find 54 in std::vector<int> \033[0m" << std::endl;


	std::vector<int>	a;
	std::vector<int>::iterator it = a.begin();

	//	Forward insertion is expensive,
	// 	because every element needs to be pushed back
	a.insert(it, 9);
	it = a.begin();
	a.insert(it, 10);
	it = a.begin();
	a.insert(it, 11);
	it = a.begin();
	a.insert(it, 12);
	it = a.begin();
	a.insert(it, 13);
	it = a.begin();

	printSequenceContainer(a);


	//TEST 1
	int num = 54;
	try{
		std::vector<int>::iterator it = easyfind(a, num);
		std::cout << "Found " << *it << std::endl;
		int index = std::distance(a.begin(), it);
		std::cout << "Found " << *it << " at index: " << index << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printNewline();


	a.push_back(2);
	a.push_back(52);
	a.push_back(54);

	std::cout << "\033[32mTest #2 : Try to find 2 in std::vector<int> \033[0m" << std::endl;


	printSequenceContainer(a);

	//Test 2
	num = 2;
	try{
		std::vector<int>::iterator it = easyfind(a, num);
		std::cout << "Found " << *it << std::endl;
		int index = std::distance(a.begin(), it);
		std::cout << "Found " << *it << " at index: " << index << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	printNewline();

	{
		// Test3 const iterator
		const std::vector<int> a(5, 42); // 5 elements with the value 42

		std::cout << "\033[32mTest #3 : Const_iterator \033[0m" << std::endl;

		printSequenceContainer(a);

		num = 2;
		try{
			std::vector<int>::const_iterator it = easyfind(a, num);
			std::cout << "Found " << *it << std::endl;
			int index = std::distance(a.begin(), it);
			std::cout << "Found " << *it << " at index: " << index << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

	}

}



void	listTests() {

	//std::vector<int>::reverse_iterator rev = a.rbegin();

	std::cout << "\033[32mTest #1 : Try to find 11 in std::list<int> \033[0m" << std::endl;


	std::list<int>	a;
	std::list<int>::iterator it = a.begin();

	//	Forward insertion is expensive,
	// 	because every element needs to be pushed back
	a.insert(it, 2);
	it = a.begin();
	a.insert(it, 0);
	it = a.begin();
	a.insert(it, -11);
	it = a.begin();
	a.insert(it, 1234);
	it = a.begin();
	a.insert(it, -56);
	it = a.begin();

	printSequenceContainer(a);


	//TEST 1
	int num = 11;
	try{
		std::list<int>::iterator it = easyfind(a, num);
		int index = std::distance(a.begin(), it);
		std::cout << "Found " << *it << " at index: " << index << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printNewline();


	a.push_back(223);
	a.push_back(-4);
	a.push_back(543);

	std::cout << "\033[32mTest #2 : Try to find -4 in std::list<int> \033[0m" << std::endl;

	printSequenceContainer(a);

	num = -4;

	//Test 2
	try{
		std::list<int>::iterator it = easyfind(a, num);
		int index = std::distance(a.begin(), it);
		std::cout << "Found " << *it << " at index: " << index << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}



void	dequeTests() {

	//std::vector<int>::reverse_iterator rev = a.rbegin();

	std::cout << "\033[32mTest #1 : Try to find 11 in std::deque<int> \033[0m" << std::endl;


	std::deque<int>	a;
	std::deque<int>::iterator it = a.begin();

	//	Forward insertion is expensive,
	// 	because every element needs to be pushed back
	a.insert(it, 2);
	it = a.begin();
	a.insert(it, 0);
	it = a.begin();
	a.insert(it, -11);
	it = a.begin();
	a.insert(it, 1234);
	it = a.begin();
	a.insert(it, -56);
	it = a.begin();

	printSequenceContainer(a);


	//TEST 1
	int num = 11;
	try{
		std::deque<int>::iterator it = easyfind(a, num);
		int index = std::distance(a.begin(), it);
		std::cout << "Found " << *it << " at index: " << index << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printNewline();


	a.push_back(223);
	a.push_back(-4);
	a.push_back(543);

	std::cout << "\033[32mTest #2 : Try to find -4 in std::deque<int> \033[0m" << std::endl;

	printSequenceContainer(a);

	num = -4;

	//Test 2
	try{
		std::deque<int>::iterator it = easyfind(a, num);
		int index = std::distance(a.begin(), it);
		std::cout << "Found " << *it << " at index: " << index << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}


int	main(void)
{
	//vectorTests();
	//listTests();
	dequeTests();
	// std::list<int>		b;
	// std::deque<int>		c;


	return (0);
}