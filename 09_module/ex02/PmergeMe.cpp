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
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>


PmergeMe::PmergeMe(char **arr, int ac) :_compareOperation(0){

	parseNumbersAndFillContainer(arr, ac);
}

PmergeMe::PmergeMe(const PmergeMe &other) :
	_vector(other._vector), _deque(other._deque), _compareOperation(0) {

}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){

	if (this != &other) {

		_vector = other._vector;
		_deque = other._deque;
		_compareOperation = other._compareOperation;
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

unsigned int countDigits(unsigned int n)
{
	unsigned int count = 1;

	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return count;
}

void	print(std::string str) {

	std::cout  << str;
}

void	printNewline() {

	std::cout  << std::endl;
}

template <typename T>
void	printContainer(T container) {

	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	for(; begin != end; begin++) {

		int width = countDigits(*begin) + 1;
		std::cout << std::setw(width) << std::right << *begin;
	}
	printNewline();
}

template <typename T>
void	printPairs(T& pairVec) {

	typename T::iterator begin = pairVec.begin();
	typename T::iterator end = pairVec.end();
	for(; begin != end; begin++ ) {

		std::cout 	<< "First: " << begin->first
					<< " Second: " <<  begin->second
					<< std::endl;
	}
}

pairVector	makePairs(containerVector& vector) {

	containerVector::iterator begin = vector.begin();
	containerVector::iterator end = vector.end();
	std::pair<unsigned int, unsigned int> pair;
	pairVector pairVec;

	for(; begin != end; ++begin) {

		if ((pairVec.size() * 2 + 1) == vector.size() )
			break;
		pair = std::make_pair(*begin, *(begin + 1));
		pairVec.push_back(pair);
		if (begin + 1 != end)
			++begin;

	}
	return pairVec;
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
		if (num < 1 || num > UINT_MAX)
			throw std::runtime_error("Error: number not in range from 1 to INT_MAX");

		_vector.push_back(static_cast<unsigned int> (num));
		_deque.push_back(static_cast<unsigned int> (num));
	}
}

void	PmergeMe::comparePairs(pairVector& pairVec,
			std::vector<unsigned int>& smaller,
			std::vector<unsigned int>& bigger) {

	pairVector::iterator begin = pairVec.begin();
	pairVector::iterator end = pairVec.end();

	for(; begin != end; begin++) {

		if (begin->first < begin->second) {

			smaller.push_back((begin->first));
			bigger.push_back((begin->second));
		}
		else {

			smaller.push_back((begin->second));
			bigger.push_back((begin->first));
		}
		_compareOperation++;
	}
}

void	jacobsIndex(std::vector<unsigned int>& smaller) {

	return;
}


containerVector& PmergeMe::sortVector(containerVector& vector) {

	if (vector.size() <= 1)
		return vector;

	ssize_t leftover = -1;
	pairVector pairVec = makePairs(vector);

	if ((pairVec.size() * 2 + 1) == vector.size() )
		leftover = *(vector.end() - 1);

	printPairs(pairVec);	//TODO: delete later, debug print

	if (leftover != -1)
		std::cout << "leftover: " << leftover << std::endl;

	printNewline();
	std::vector<unsigned int> smaller;
	std::vector<unsigned int> bigger;

	comparePairs(pairVec, smaller, bigger);

	print("SMALLER\t");
	printContainer(smaller);
	print("BIGGER\t");
	printContainer(bigger);

	printNewline();

	//std::cout << "Bigger Size " << bigger.size() << std::endl;

	std::vector<unsigned int> mainVec = sortVector(bigger);


	jacobsIndex(smaller);



	// print("MAIN VEC\t");
	// printContainer(mainVec);

	//std::cout << "Compare " << _compareOperation << std::endl;








	return vector;
}

containerDeque&	PmergeMe::sortDeque(containerDeque& deque) {

	return deque;
}

void	PmergeMe::runSort() {

	if (_vector.empty() || _deque.empty())
		throw std::runtime_error("Error: container empty");


	// ######################################################################
	// SORT VECTOR

	time startVector = getTimeUsec();
	containerVector sortedVector = sortVector(_vector);
	time endVector = getTimeUsec();
	time vectorTime = endVector - startVector;


	// ######################################################################
	// SORT DEQUE

	time startDeque = getTimeUsec();
	containerDeque sortedDeque = sortDeque(_deque);
	time endDeque = getTimeUsec();
	time dequeTime = endDeque - startDeque;


	// ######################################################################
	// PRINT

	std::cout << "Before:\t";
	printContainer(_vector);

	std::cout << " After:\t";
	printContainer(sortedVector);

	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of "
		<< _vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;

	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of "
		<< _deque.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
}








