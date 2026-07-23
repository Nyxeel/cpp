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
#include <sys/types.h>


PmergeMe::PmergeMe() : _vectorComparisons(0), _dequeComparisons(0) {

}

PmergeMe::PmergeMe(char **arr, int ac) :
	_vectorComparisons(0), _dequeComparisons(0) {

	parseNumbersAndFillContainer(arr, ac);
}

PmergeMe::PmergeMe(const PmergeMe &other) :
	_vector(other._vector), _deque(other._deque),
	_vectorComparisons(other._vectorComparisons),
	_dequeComparisons(other._dequeComparisons) {

}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){

	if (this != &other) {

		_vector = other._vector;
		_deque = other._deque;
		_vectorComparisons = other._vectorComparisons;
		_dequeComparisons = other._dequeComparisons;
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
	return ((double)tv.tv_sec * 1000000.0 + (double)tv.tv_usec);
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


// ######################################################################
// #########################  V E C T O R  ##############################
// ######################################################################


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
		_vectorComparisons++;
	}
}


std::vector<ssize_t>	getJacobsIndex(std::vector<unsigned int>& smaller) {

	std::vector<ssize_t> arr;

	ssize_t smallerSize = smaller.size();
	if (smallerSize == 1) {

		arr.push_back(0);
		return (arr);
	}

	ssize_t prev0 = 0;
	ssize_t prev1 = 1;
	ssize_t jacobsBorderNum = 0;
	while (smallerSize >= jacobsBorderNum) {

		jacobsBorderNum = prev1 + 2 * prev0; 	// Jacobs Num Calc
		if (jacobsBorderNum <= smallerSize)
			arr.push_back(jacobsBorderNum - 1);

		ssize_t tmp = jacobsBorderNum;
		while (tmp > prev1) {

			tmp -= 1;
			if (tmp <= smallerSize && tmp != prev1)
				arr.push_back(tmp - 1);
		}
		prev0 = prev1;
		prev1 = jacobsBorderNum;
	}
	return arr;
}

std::vector<unsigned int>::iterator	binaryInsert(
		unsigned int target,
		std::vector<unsigned int>::iterator start,
		std::vector<unsigned int>::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	std::vector<unsigned int>::iterator middle = start + (end - start) / 2;

	comparisons++;
	if (target <= *middle)
			return (binaryInsert(target, start, middle, comparisons));

	if (target > *middle)
		return (binaryInsert(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


std::vector<unsigned int>&	insertSmaller(
			std::vector<ssize_t>& jacobsIndexVec,
			std::vector<unsigned int>& smaller,
			std::vector<unsigned int>& mainVec,
			size_t& comparisons) {

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();
	std::vector<unsigned int>::iterator smallBegin = smaller.begin();

	for( ; idx != end; idx++) {

		std::vector<unsigned int>::iterator pos = binaryInsert(smallBegin[*idx], mainVec.begin(), mainVec.end(), comparisons);

		//std::cout << " insert " << smallBegin[*idx] << " before number " << *pos << "\n";
		mainVec.insert(pos, smallBegin[*idx]);
	}
	return mainVec;
}

containerVector PmergeMe::sortVector(containerVector& vector) {

	if (vector.size() <= 1)
		return vector;

	ssize_t leftover = -1;
	pairVector pairVec = makePairs(vector);

	if ((pairVec.size() * 2 + 1) == vector.size() )
		leftover = *(vector.end() - 1);

	std::vector<unsigned int> smaller;
	std::vector<unsigned int> bigger;

	comparePairs(pairVec, smaller, bigger);

	std::vector<unsigned int> mainVec = sortVector(bigger);
	std::vector<ssize_t> jacobsIndexVec = getJacobsIndex(smaller);

	mainVec = insertSmaller(jacobsIndexVec, smaller, mainVec, _vectorComparisons);

	if (leftover != -1) {

		std::vector<unsigned int>::iterator pos = binaryInsert(leftover, mainVec.begin(), mainVec.end(), _vectorComparisons);
		mainVec.insert(pos, leftover);
	}
	return mainVec;
}



// ######################################################################
// #########################   D E Q U E   ##############################
// ######################################################################

pairDeque	makePairs(containerDeque& deque) {

	containerDeque::iterator begin = deque.begin();
	containerDeque::iterator end = deque.end();
	std::pair<unsigned int, unsigned int> pair;
	pairDeque pairDeque;

	for(; begin != end; ++begin) {

		if ((pairDeque.size() * 2 + 1) == deque.size() )
			break;
		pair = std::make_pair(*begin, *(begin + 1));
		pairDeque.push_back(pair);
		if (begin + 1 != end)
			++begin;

	}
	return pairDeque;
}


void	PmergeMe::comparePairs(pairDeque& pairDeque,
			std::deque<unsigned int>& smaller,
			std::deque<unsigned int>& bigger) {

	pairDeque::iterator begin = pairDeque.begin();
	pairDeque::iterator end = pairDeque.end();

	for(; begin != end; begin++) {

		if (begin->first < begin->second) {

			smaller.push_back((begin->first));
			bigger.push_back((begin->second));
		}
		else {

			smaller.push_back((begin->second));
			bigger.push_back((begin->first));
		}
		_dequeComparisons++;
	}
}


std::deque<ssize_t>	getJacobsIndex(std::deque<unsigned int>& smaller) {

	std::deque<ssize_t> arr;

	ssize_t smallerSize = smaller.size();
	if (smallerSize == 1) {

		arr.push_back(0);
		return (arr);
	}

	ssize_t prev0 = 0;
	ssize_t prev1 = 1;
	ssize_t jacobsBorderNum = 0;
	while (smallerSize >= jacobsBorderNum) {

		jacobsBorderNum = prev1 + 2 * prev0; 	// Jacobs Num Calc
		if (jacobsBorderNum <= smallerSize)
			arr.push_back(jacobsBorderNum - 1);

		ssize_t tmp = jacobsBorderNum;
		while (tmp > prev1) {

			tmp -= 1;
			if (tmp <= smallerSize && tmp != prev1)
				arr.push_back(tmp - 1);
		}
		prev0 = prev1;
		prev1 = jacobsBorderNum;
	}
	return arr;
}


std::deque<unsigned int>::iterator	binaryInsert(
		unsigned int target,
		std::deque<unsigned int>::iterator start,
		std::deque<unsigned int>::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	std::deque<unsigned int>::iterator middle = start + (end - start) / 2;

	comparisons++;
	if (target <= *middle)
			return (binaryInsert(target, start, middle, comparisons));

	if (target > *middle)
		return (binaryInsert(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


std::deque<unsigned int>&	insertSmaller(
			std::deque<ssize_t>& jacobsIndexVec,
			std::deque<unsigned int>& smaller,
			std::deque<unsigned int>& mainDeque,
			size_t& comparisons) {

	std::deque<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::deque<ssize_t>::iterator end = jacobsIndexVec.end();
	std::deque<unsigned int>::iterator smallBegin = smaller.begin();

	for( ; idx != end; idx++) {

		std::deque<unsigned int>::iterator pos = binaryInsert(smallBegin[*idx], mainDeque.begin(), mainDeque.end(), comparisons);

		//std::cout << " insert " << smallBegin[*idx] << " before number " << *pos << "\n";
		mainDeque.insert(pos, smallBegin[*idx]);
	}
	return mainDeque;
}



containerDeque PmergeMe::sortDeque(containerDeque& deque) {

	if (deque.size() <= 1)
		return deque;

	ssize_t leftover = -1;
	pairDeque pairDeque = makePairs(deque);

	if ((pairDeque.size() * 2 + 1) == deque.size() )
		leftover = *(deque.end() - 1);

	std::deque<unsigned int> smaller;
	std::deque<unsigned int> bigger;

	comparePairs(pairDeque, smaller, bigger);

	std::deque<unsigned int> mainDeque = sortDeque(bigger);
	std::deque<ssize_t> jacobsIndexDeque = getJacobsIndex(smaller);

	mainDeque = insertSmaller(jacobsIndexDeque, smaller, mainDeque, _dequeComparisons);

	if (leftover != -1) {

		std::deque<unsigned int>::iterator pos = binaryInsert(leftover, mainDeque.begin(), mainDeque.end(), _dequeComparisons);
		mainDeque.insert(pos, leftover);
	}
	return mainDeque;
}


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

	std::cout << "Time to process a range of "
		<< _vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;

	std::cout << "Time to process a range of "
		<< _deque.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;

	std::cout << "Comparisons used for std::vector : " << _vectorComparisons << std::endl;
	std::cout << "Comparisons used for std::deque : " << _dequeComparisons << std::endl;
}








