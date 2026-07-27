/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.Vector.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <stdexcept>
#include <map>


// ######################################################################
// #########################  V E C T O R  ##############################
// ######################################################################


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


void	PmergeMe::comparePairsIndexed(IndexedPairVector& pairVec,
			IndexedVector& smaller,
			IndexedVector& bigger) {

	IndexedPairVector::iterator begin = pairVec.begin();
	IndexedPairVector::iterator end = pairVec.end();

	for(; begin != end; begin++) {

		// IndexedPairVec has pair inside a pair!
		if (begin->first.first < begin->second.first) {

			smaller.push_back(begin->first);
			bigger.push_back(begin->second);
		}
		else {

			smaller.push_back(begin->second);
			bigger.push_back(begin->first);
		}
		if (DEBUG)
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

	if (DEBUG)
		comparisons++;
	if (target.first <= middle->first)
			return (binaryInsertIndexed(target, start, middle, comparisons));

	if (target.first > middle->first)
		return (binaryInsertIndexed(target, middle + 1, end, comparisons));
	throw std::runtime_error("Error");
}



IndexedVector&	insertSmallerIndexed(
			std::vector<ssize_t>& jacobsIndexVec,
			IndexedVector& smallerPending,
			IndexedVector& biggerOrdered,
			size_t realCount,
			IndexedVector& mainVec,
			size_t& comparisons) {

	// einmaliger Durchlauf: id -> aktuelle Position in mainVec (kein Suchen noetig)
	std::map<size_t, size_t> positionOf;
	for (size_t i = 0; i < mainVec.size(); i++)
		positionOf[mainVec[i].second] = i;

	std::vector<ssize_t>::iterator idx = jacobsIndexVec.begin();
	std::vector<ssize_t>::iterator end = jacobsIndexVec.end();

	for( ; idx != end; idx++) {

		//selects number to insert from smaller Pending via jacobs idx
		IndexedValue target = smallerPending[*idx];
		size_t bound;

		// sets the boundaries for smaller value by accessing the map
		// so it tells binaryInserIndexed where end is
		if (static_cast<size_t>(*idx) < realCount)
			bound = positionOf[biggerOrdered[*idx].second];
		else
			bound = mainVec.size();		// Leftover

		IndexedVector::iterator pos = binaryInsertIndexed(target, mainVec.begin(), mainVec.begin() + bound, comparisons);
		size_t insertIndex = pos - mainVec.begin();

		mainVec.insert(pos, target);

		// mainVec is contains now 1 more element, which makes the index in positionOf from insertIndex 1 bigger!
		std::map<size_t, size_t>::iterator mapBegin = positionOf.begin();
		std::map<size_t, size_t>::iterator mapEnd = positionOf.end();
		for (; mapBegin != mapEnd; ++mapBegin) {

			if (mapBegin->second >= insertIndex)
				mapBegin->second++;
		}
	}
	return mainVec;
}


// baut biggerOrdered (Kopie von mainVec) und smallerPending (smaller-Partner an derselben
// Position wie ihr bigger-Partner in biggerOrdered), verbindet dafuer ueber die id
void	buildSmallerBiggerInOrder(
			IndexedVector& smaller,
			IndexedVector& bigger,
			IndexedVector& mainVec,
			IndexedVector& smallerPending,
			IndexedVector& biggerOrdered) {

	// connect bigger id to former smaller partner via bigger id
	std::map<size_t, IndexedValue> idToSmaller;
	for (size_t k = 0; k < bigger.size(); k++)
		idToSmaller[bigger[k].second] = smaller[k];
		//			^id from bigger   = ^value froma smaller parter

	for (size_t p = 0; p < mainVec.size(); p++) {

		biggerOrdered.push_back(mainVec[p]);
		smallerPending.push_back(idToSmaller[mainVec[p].second]);
	}
}


// recursive Ford Johnson core
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

	// split into smaller and bigger
	comparePairsIndexed(pairVec, smaller, bigger);

	//recursiv call with bigger
	IndexedVector mainVec = sortVectorIndexed(bigger);


	IndexedVector smallerPending;
	IndexedVector biggerOrdered;

	//create 2 vecs
	//BiggerOrdered is a copy of mainVec
	//smallerPending is a vec where the smaller parnter num is on the same index as their bigger Partner in biggerOrdered
	buildSmallerBiggerInOrder(smaller, bigger, mainVec, smallerPending, biggerOrdered);

	size_t realCount = smallerPending.size();
	if (hasLeftover)
		smallerPending.push_back(leftover);

	// sets the order which index of smallerPending is inserted into mainVec
	// reduces comparision operations
	std::vector<ssize_t> jacobsIndexVec = getJacobsIndex(smallerPending.size());

	mainVec = insertSmallerIndexed(jacobsIndexVec, smallerPending, biggerOrdered, realCount, mainVec, _vectorComparisons);

	return mainVec;
}



containerVector PmergeMe::sortVector(containerVector& vector) {

	IndexedVector indexed;
	// makes a Pair of value and index
	for (size_t i = 0; i < vector.size(); i++)
		indexed.push_back(std::make_pair(vector[i], i));

	IndexedVector sorted = sortVectorIndexed(indexed);

	containerVector result;
	for (size_t i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i].first);
	return result;
}
