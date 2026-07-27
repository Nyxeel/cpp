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
#include <map>


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


// liefert die Jacobsthal-Einfuegereihenfolge (Indizes in "smaller") fuer n Elemente
std::vector<ssize_t>	getJacobsIndex(size_t smallerSizeIn) {

	std::vector<ssize_t> arr;

	ssize_t smallerSize = smallerSizeIn;
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


// gruppiert aufeinanderfolgende Elemente zu Paaren (smaller,bigger), traegt die id unveraendert mit
IndexedPairVector	makeIndexedPairs(IndexedVector& vec) {

	IndexedVector::iterator begin = vec.begin();
	IndexedVector::iterator end = vec.end();
	IndexedPairVector pairVec;

	for(; begin != end; ++begin) {

		if ((pairVec.size() * 2 + 1) == vec.size() )
			break;
		pairVec.push_back(std::make_pair(*begin, *(begin + 1)));
		if (begin + 1 != end)
			++begin;

	}
	return pairVec;
}


// vergleicht jedes Paar nach .first (Wert); .second (id) bleibt am Element haengen
void	PmergeMe::comparePairsIndexed(IndexedPairVector& pairVec,
			IndexedVector& smaller,
			IndexedVector& bigger) {

	IndexedPairVector::iterator begin = pairVec.begin();
	IndexedPairVector::iterator end = pairVec.end();

	for(; begin != end; begin++) {

		if (begin->first.first < begin->second.first) {

			smaller.push_back(begin->first);
			bigger.push_back(begin->second);
		}
		else {

			smaller.push_back(begin->second);
			bigger.push_back(begin->first);
		}
		_vectorComparisons++;
	}
}


// binaere Suche nach der Einfuegeposition von target im Bereich [start,end)
IndexedVector::iterator	binaryInsertIndexed(
		IndexedValue target,
		IndexedVector::iterator start,
		IndexedVector::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	IndexedVector::iterator middle = start + (end - start) / 2;

	comparisons++;
	if (target.first <= middle->first)
			return (binaryInsertIndexed(target, start, middle, comparisons));

	if (target.first > middle->first)
		return (binaryInsertIndexed(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


// fuegt jedes smaller-Element in Jacobsthal-Reihenfolge ein; sucht nur bis zur bekannten Position des zugehoerigen bigger-Elements
IndexedVector&	insertSmallerIndexed(
			std::vector<ssize_t>& jacobsIndexVec,
			IndexedVector& smaller,
			IndexedVector& bigger,
			IndexedVector& mainVec,
			size_t& comparisons) {

	// einmaliger Durchlauf: id -> aktuelle Position in mainVec (kein Suchen noetig)
	std::map<size_t, size_t> positionOf;
	for (size_t i = 0; i < mainVec.size(); i++)
		positionOf[mainVec[i].second] = i;

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();

	for( ; idx != end; idx++) {

		IndexedValue target = smaller[*idx];
		size_t partnerId = bigger[*idx].second;
		size_t bound = positionOf[partnerId];		// Obergrenze = Position des bigger-Partners, statt end()

		IndexedVector::iterator pos = binaryInsertIndexed(target, mainVec.begin(), mainVec.begin() + bound, comparisons);
		size_t insertIndex = pos - mainVec.begin();

		mainVec.insert(pos, target);

		// Verschiebung durch die Einfuegung nachfuehren: alle Positionen ab insertIndex ruecken um 1
		std::map<size_t, size_t>::iterator mapIt = positionOf.begin();
		std::map<size_t, size_t>::iterator mapEnd = positionOf.end();
		for (; mapIt != mapEnd; ++mapIt) {

			if (mapIt->second >= insertIndex)
				mapIt->second++;
		}
	}
	return mainVec;
}


// rekursiver Ford Johnson core
IndexedVector	PmergeMe::sortVectorIndexed(IndexedVector& vec) {

	if (vec.size() <= 1)
		return vec;

	bool hasLeftover = false;
	IndexedValue leftover;
	IndexedPairVector pairVec = makeIndexedPairs(vec);

	if ((pairVec.size() * 2 + 1) == vec.size() ) {

		hasLeftover = true;
		leftover = *(vec.end() - 1);
	}

	IndexedVector smaller;
	IndexedVector bigger;

	comparePairsIndexed(pairVec, smaller, bigger);

	IndexedVector mainVec = sortVectorIndexed(bigger);
	std::vector<ssize_t> jacobsIndexVec = getJacobsIndex(smaller.size());

	mainVec = insertSmallerIndexed(jacobsIndexVec, smaller, bigger, mainVec, _vectorComparisons);

	if (hasLeftover) {

		IndexedVector::iterator pos = binaryInsertIndexed(leftover, mainVec.begin(), mainVec.end(), _vectorComparisons);
		mainVec.insert(pos, leftover);
	}
	return mainVec;
}


// indiziert die Werte und ID
containerVector PmergeMe::sortVector(containerVector& vector) {

	IndexedVector indexed;
	for (size_t i = 0; i < vector.size(); i++)
		indexed.push_back(std::make_pair(vector[i], i));

	IndexedVector sorted = sortVectorIndexed(indexed);

	containerVector result;
	for (size_t i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i].first);
	return result;
}



// ######################################################################
// #########################   D E Q U E   ##############################
// ######################################################################

// gruppiert aufeinanderfolgende Elemente zu Paaren (smaller,bigger), traegt die id unveraendert mit
IndexedPairDeque	makeIndexedPairs(IndexedDeque& deq) {

	IndexedDeque::iterator begin = deq.begin();
	IndexedDeque::iterator end = deq.end();
	IndexedPairDeque pairDeq;

	for(; begin != end; ++begin) {

		if ((pairDeq.size() * 2 + 1) == deq.size() )
			break;
		pairDeq.push_back(std::make_pair(*begin, *(begin + 1)));
		if (begin + 1 != end)
			++begin;

	}
	return pairDeq;
}


// vergleicht jedes Paar nach .first (Wert); .second (id) bleibt am Element haengen
void	PmergeMe::comparePairsIndexed(IndexedPairDeque& pairVec,
			IndexedDeque& smaller,
			IndexedDeque& bigger) {

	IndexedPairDeque::iterator begin = pairVec.begin();
	IndexedPairDeque::iterator end = pairVec.end();

	for(; begin != end; begin++) {

		if (begin->first.first < begin->second.first) {

			smaller.push_back(begin->first);
			bigger.push_back(begin->second);
		}
		else {

			smaller.push_back(begin->second);
			bigger.push_back(begin->first);
		}
		_dequeComparisons++;
	}
}


// binaere Suche nach der Einfuegeposition von target im Bereich [start,end)
IndexedDeque::iterator	binaryInsertIndexed(
		IndexedValue target,
		IndexedDeque::iterator start,
		IndexedDeque::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	IndexedDeque::iterator middle = start + (end - start) / 2;

	comparisons++;
	if (target.first <= middle->first)
			return (binaryInsertIndexed(target, start, middle, comparisons));

	if (target.first > middle->first)
		return (binaryInsertIndexed(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


// fuegt jedes smaller-Element in Jacobsthal-Reihenfolge ein; sucht nur bis zur bekannten Position des zugehoerigen bigger-Elements
IndexedDeque&	insertSmallerIndexed(
			std::vector<ssize_t>& jacobsIndexVec,
			IndexedDeque& smaller,
			IndexedDeque& bigger,
			IndexedDeque& mainDeque,
			size_t& comparisons) {

	// einmaliger Durchlauf: id -> aktuelle Position in mainDeque (kein Suchen noetig)
	std::map<size_t, size_t> positionOf;
	for (size_t i = 0; i < mainDeque.size(); i++)
		positionOf[mainDeque[i].second] = i;

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();

	for( ; idx != end; idx++) {

		IndexedValue target = smaller[*idx];
		size_t partnerId = bigger[*idx].second;
		size_t bound = positionOf[partnerId];		// Obergrenze = Position des bigger-Partners, statt end()

		IndexedDeque::iterator pos = binaryInsertIndexed(target, mainDeque.begin(), mainDeque.begin() + bound, comparisons);
		size_t insertIndex = pos - mainDeque.begin();

		mainDeque.insert(pos, target);

		// Verschiebung durch die Einfuegung nachfuehren: alle Positionen ab insertIndex ruecken um 1
		std::map<size_t, size_t>::iterator mapIt = positionOf.begin();
		std::map<size_t, size_t>::iterator mapEnd = positionOf.end();
		for (; mapIt != mapEnd; ++mapIt) {

			if (mapIt->second >= insertIndex)
				mapIt->second++;
		}
	}
	return mainDeque;
}



// eigentlicher rekursiver Ford-Johnson-Kern, arbeitet auf indizierten Werten
IndexedDeque	PmergeMe::sortDequeIndexed(IndexedDeque& deq) {

	if (deq.size() <= 1)
		return deq;

	bool hasLeftover = false;
	IndexedValue leftover;
	IndexedPairDeque pairDeq = makeIndexedPairs(deq);

	if ((pairDeq.size() * 2 + 1) == deq.size() ) {

		hasLeftover = true;
		leftover = *(deq.end() - 1);
	}

	IndexedDeque smaller;
	IndexedDeque bigger;

	comparePairsIndexed(pairDeq, smaller, bigger);

	IndexedDeque mainDeque = sortDequeIndexed(bigger);
	std::vector<ssize_t> jacobsIndexDeque = getJacobsIndex(smaller.size());

	mainDeque = insertSmallerIndexed(jacobsIndexDeque, smaller, bigger, mainDeque, _dequeComparisons);

	if (hasLeftover) {

		IndexedDeque::iterator pos = binaryInsertIndexed(leftover, mainDeque.begin(), mainDeque.end(), _dequeComparisons);
		mainDeque.insert(pos, leftover);
	}
	return mainDeque;
}


// oeffentliche API: indiziert die Werte, ruft den indizierten Kern auf, streift die ids wieder ab
containerDeque PmergeMe::sortDeque(containerDeque& deque) {

	IndexedDeque indexed;
	for (size_t i = 0; i < deque.size(); i++)
		indexed.push_back(std::make_pair(deque[i], i));

	IndexedDeque sorted = sortDequeIndexed(indexed);

	containerDeque result;
	for (size_t i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i].first);
	return result;
}


void	PmergeMe::parseNumbersAndFillContainer(char **arr, int ac) {

	for (int i = 1; i < ac; i++) {

		char* endptr = NULL;
		double num = strtod(arr[i], &endptr);
		if (*endptr != '\0')
			throw std::runtime_error("Error: invalid char detected");
		if (num < 1 || num > UINT_MAX)
			throw std::runtime_error("Error: number not in range from 1 to UINT_MAX");

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








