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


// gruppiert aufeinanderfolgende Elemente zu Paaren (ak,bk), traegt die id unveraendert mit
taggedPairVector	makeTaggedPairs(taggedVector& vec) {

	taggedVector::iterator begin = vec.begin();
	taggedVector::iterator end = vec.end();
	taggedPairVector pairVec;

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
void	PmergeMe::comparePairsTagged(taggedPairVector& pairVec,
			taggedVector& smaller,
			taggedVector& bigger) {

	taggedPairVector::iterator begin = pairVec.begin();
	taggedPairVector::iterator end = pairVec.end();

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
taggedVector::iterator	binaryInsertTagged(
		TaggedUint target,
		taggedVector::iterator start,
		taggedVector::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	taggedVector::iterator middle = start + (end - start) / 2;

	comparisons++;
	if (target.first <= middle->first)
			return (binaryInsertTagged(target, start, middle, comparisons));

	if (target.first > middle->first)
		return (binaryInsertTagged(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


// fuegt jedes ak in Jacobsthal-Reihenfolge ein; sucht nur bis zur bekannten Position von bk
taggedVector&	insertSmallerTagged(
			std::vector<ssize_t>& jacobsIndexVec,
			taggedVector& smaller,
			taggedVector& bigger,
			taggedVector& mainVec,
			size_t& comparisons) {

	// einmaliger Durchlauf: id -> aktuelle Position in mainVec (kein Suchen noetig)
	std::map<size_t, size_t> positionOf;
	for (size_t i = 0; i < mainVec.size(); i++)
		positionOf[mainVec[i].second] = i;

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();

	for( ; idx != end; idx++) {

		TaggedUint target = smaller[*idx];
		size_t partnerId = bigger[*idx].second;
		size_t bound = positionOf[partnerId];		// Obergrenze = Position von bk, statt end()

		taggedVector::iterator pos = binaryInsertTagged(target, mainVec.begin(), mainVec.begin() + bound, comparisons);
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


// eigentlicher rekursiver Ford-Johnson-Kern, arbeitet auf getaggten Werten
taggedVector	PmergeMe::sortVectorTagged(taggedVector& vec) {

	if (vec.size() <= 1)
		return vec;

	bool hasLeftover = false;
	TaggedUint leftover;
	taggedPairVector pairVec = makeTaggedPairs(vec);

	if ((pairVec.size() * 2 + 1) == vec.size() ) {

		hasLeftover = true;
		leftover = *(vec.end() - 1);
	}

	taggedVector smaller;
	taggedVector bigger;

	comparePairsTagged(pairVec, smaller, bigger);

	taggedVector mainVec = sortVectorTagged(bigger);
	std::vector<ssize_t> jacobsIndexVec = getJacobsIndex(smaller.size());

	mainVec = insertSmallerTagged(jacobsIndexVec, smaller, bigger, mainVec, _vectorComparisons);

	if (hasLeftover) {

		taggedVector::iterator pos = binaryInsertTagged(leftover, mainVec.begin(), mainVec.end(), _vectorComparisons);
		mainVec.insert(pos, leftover);
	}
	return mainVec;
}


// oeffentliche API: taggt die Werte, ruft den getaggten Kern auf, streift die ids wieder ab
containerVector PmergeMe::sortVector(containerVector& vector) {

	taggedVector tagged;
	for (size_t i = 0; i < vector.size(); i++)
		tagged.push_back(std::make_pair(vector[i], i));

	taggedVector sorted = sortVectorTagged(tagged);

	containerVector result;
	for (size_t i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i].first);
	return result;
}



// ######################################################################
// #########################   D E Q U E   ##############################
// ######################################################################

// gruppiert aufeinanderfolgende Elemente zu Paaren (ak,bk), traegt die id unveraendert mit
taggedPairDeque	makeTaggedPairs(taggedDeque& deq) {

	taggedDeque::iterator begin = deq.begin();
	taggedDeque::iterator end = deq.end();
	taggedPairDeque pairDeq;

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
void	PmergeMe::comparePairsTagged(taggedPairDeque& pairVec,
			taggedDeque& smaller,
			taggedDeque& bigger) {

	taggedPairDeque::iterator begin = pairVec.begin();
	taggedPairDeque::iterator end = pairVec.end();

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
taggedDeque::iterator	binaryInsertTagged(
		TaggedUint target,
		taggedDeque::iterator start,
		taggedDeque::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	taggedDeque::iterator middle = start + (end - start) / 2;

	comparisons++;
	if (target.first <= middle->first)
			return (binaryInsertTagged(target, start, middle, comparisons));

	if (target.first > middle->first)
		return (binaryInsertTagged(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


// fuegt jedes ak in Jacobsthal-Reihenfolge ein; sucht nur bis zur bekannten Position von bk
taggedDeque&	insertSmallerTagged(
			std::vector<ssize_t>& jacobsIndexVec,
			taggedDeque& smaller,
			taggedDeque& bigger,
			taggedDeque& mainDeque,
			size_t& comparisons) {

	// einmaliger Durchlauf: id -> aktuelle Position in mainDeque (kein Suchen noetig)
	std::map<size_t, size_t> positionOf;
	for (size_t i = 0; i < mainDeque.size(); i++)
		positionOf[mainDeque[i].second] = i;

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();

	for( ; idx != end; idx++) {

		TaggedUint target = smaller[*idx];
		size_t partnerId = bigger[*idx].second;
		size_t bound = positionOf[partnerId];		// Obergrenze = Position von bk, statt end()

		taggedDeque::iterator pos = binaryInsertTagged(target, mainDeque.begin(), mainDeque.begin() + bound, comparisons);
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



// eigentlicher rekursiver Ford-Johnson-Kern, arbeitet auf getaggten Werten
taggedDeque	PmergeMe::sortDequeTagged(taggedDeque& deq) {

	if (deq.size() <= 1)
		return deq;

	bool hasLeftover = false;
	TaggedUint leftover;
	taggedPairDeque pairDeq = makeTaggedPairs(deq);

	if ((pairDeq.size() * 2 + 1) == deq.size() ) {

		hasLeftover = true;
		leftover = *(deq.end() - 1);
	}

	taggedDeque smaller;
	taggedDeque bigger;

	comparePairsTagged(pairDeq, smaller, bigger);

	taggedDeque mainDeque = sortDequeTagged(bigger);
	std::vector<ssize_t> jacobsIndexDeque = getJacobsIndex(smaller.size());

	mainDeque = insertSmallerTagged(jacobsIndexDeque, smaller, bigger, mainDeque, _dequeComparisons);

	if (hasLeftover) {

		taggedDeque::iterator pos = binaryInsertTagged(leftover, mainDeque.begin(), mainDeque.end(), _dequeComparisons);
		mainDeque.insert(pos, leftover);
	}
	return mainDeque;
}


// oeffentliche API: taggt die Werte, ruft den getaggten Kern auf, streift die ids wieder ab
containerDeque PmergeMe::sortDeque(containerDeque& deque) {

	taggedDeque tagged;
	for (size_t i = 0; i < deque.size(); i++)
		tagged.push_back(std::make_pair(deque[i], i));

	taggedDeque sorted = sortDequeTagged(tagged);

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








