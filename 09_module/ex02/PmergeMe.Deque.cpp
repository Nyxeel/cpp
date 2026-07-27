/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.Deque.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <stdexcept>
#include <map>


// ######################################################################
// #########################   D E Q U E   ##############################
// ######################################################################

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
		if (DEBUG)
			_dequeComparisons++;
	}
}



IndexedDeque::iterator	binaryInsertIndexed(
		IndexedValue target,
		IndexedDeque::iterator start,
		IndexedDeque::iterator end,
		size_t& comparisons) {

	if (start == end)
			return start;

	IndexedDeque::iterator middle = start + (end - start) / 2;

	if (DEBUG)
		comparisons++;
	if (target.first <= middle->first)
			return (binaryInsertIndexed(target, start, middle, comparisons));

	if (target.first > middle->first)
		return (binaryInsertIndexed(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}


IndexedDeque&	insertSmallerIndexed(
			std::vector<ssize_t>& jacobsIndexVec,
			IndexedDeque& pending,
			IndexedDeque& biggerOrdered,
			size_t realCount,
			IndexedDeque& mainDeque,
			size_t& comparisons) {

	std::map<size_t, size_t> positionOf;
	for (size_t i = 0; i < mainDeque.size(); i++)
		positionOf[mainDeque[i].second] = i;

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();

	for( ; idx != end; idx++) {

		IndexedValue target = pending[*idx];
		size_t bound;

		if (static_cast<size_t>(*idx) < realCount)
			bound = positionOf[biggerOrdered[*idx].second];
		else
			bound = mainDeque.size();
		IndexedDeque::iterator pos = binaryInsertIndexed(target, mainDeque.begin(), mainDeque.begin() + bound, comparisons);
		size_t insertIndex = pos - mainDeque.begin();

		mainDeque.insert(pos, target);

		std::map<size_t, size_t>::iterator mapIt = positionOf.begin();
		std::map<size_t, size_t>::iterator mapEnd = positionOf.end();
		for (; mapIt != mapEnd; ++mapIt) {

			if (mapIt->second >= insertIndex)
				mapIt->second++;
		}
	}
	return mainDeque;
}



void	buildSmallerBiggerInOrder(
			IndexedDeque& smaller,
			IndexedDeque& bigger,
			IndexedDeque& mainDeque,
			IndexedDeque& pending,
			IndexedDeque& biggerOrdered) {

	std::map<size_t, IndexedValue> idToSmaller;
	for (size_t k = 0; k < bigger.size(); k++)
		idToSmaller[bigger[k].second] = smaller[k];

	for (size_t p = 0; p < mainDeque.size(); p++) {

		biggerOrdered.push_back(mainDeque[p]);
		pending.push_back(idToSmaller[mainDeque[p].second]);
	}
}


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

	IndexedDeque pending;
	IndexedDeque biggerOrdered;
	buildSmallerBiggerInOrder(smaller, bigger, mainDeque, pending, biggerOrdered);

	size_t realCount = pending.size();
	if (hasLeftover)
		pending.push_back(leftover);

	std::vector<ssize_t> jacobsIndexDeque = getJacobsIndex(pending.size());

	mainDeque = insertSmallerIndexed(jacobsIndexDeque, pending, biggerOrdered, realCount, mainDeque, _dequeComparisons);

	return mainDeque;
}


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
