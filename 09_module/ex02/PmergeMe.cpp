/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:34:49 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/17 17:42:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sys/time.h>
#include <cctype>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <unistd.h>



PmergeMe::PmergeMe(char **arr, int ac){

	parseNumbersAndFillContainer(arr, ac);
}

PmergeMe::PmergeMe(const PmergeMe &other) :
	_vector(other._vector), _deque(other._deque) {

}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){

	if (this != &other) {

		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {

}


// ######################################################################
// #########################   H E L P E R   ############################
// ######################################################################

double	getTimeUsec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}

void	printNewline() {

	std::cout  << std::endl;
}

template <typename T>
void	printContainer(T container) {

	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	for(; begin != end; begin++) {

		std::cout << *begin;
		if (begin + 1 != end)
			std::cout << " ";
	}
	printNewline();
}


// ######################################################################
// ######################################################################
// ######################################################################


void	PmergeMe::parseNumbersAndFillContainer(char **arr, int ac) {

	for (int i = 1; i < ac; i++) {

		char* endptr = NULL;
		double num = strtod(arr[i], &endptr);
		if (*endptr != '\0')
			throw std::runtime_error("Error: invalid char detected");
		if (num < 1 || num > INT_MAX)
			throw std::runtime_error("Error: number not in range from 1 to INT_MAX");
		_vector.push_back(static_cast<int> (num));
		_deque.push_back(static_cast<int> (num));
	}
}


void	PmergeMe::sortVector() {


	return ;
}

void	PmergeMe::sortDeque() {

	return ;
}

void	PmergeMe::runSort() {

	if (_vector.empty() || _deque.empty())
		throw std::runtime_error("Error: container empty");

	std::vector<int> vectorBefore = _vector;


	// ######################################################################
	// SORT VECTOR
	
	time startVector = getTimeUsec();
	sortVector();
	time endVector = getTimeUsec();
	time vectorTime = endVector - startVector;



	// ######################################################################
	// SORT DEQUE

	time startDeque = getTimeUsec();
	sortDeque();
	time endDeque = getTimeUsec();
	time dequeTime = endDeque - startDeque;


	// ######################################################################
	// PRINT

	std::cout << "Before: ";
	printContainer(_vector);

	std::cout << "After: ";
	printContainer(_vector);

	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of "
		<< _vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;

	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of "
		<< _deque.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
}








