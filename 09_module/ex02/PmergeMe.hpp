/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:34:49 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/16 20:02:36 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP


#ifndef DEBUG
# define DEBUG 0
#endif

#include <vector>
#include <deque>
#include <cstddef>
#include <utility>
#include <sys/types.h>
#include <iomanip>
#include <iostream>


typedef std::vector<unsigned int> containerVector;
typedef std::deque<unsigned int> containerDeque;

typedef std::pair<unsigned int, size_t> IndexedValue;

typedef std::vector<IndexedValue> IndexedVector;
typedef std::vector<std::pair<IndexedValue, IndexedValue> > IndexedPairVector;

typedef std::deque<IndexedValue> IndexedDeque;
typedef std::deque<std::pair<IndexedValue, IndexedValue> > IndexedPairDeque;

class PmergeMe {

	typedef double time;

	private:

		void						parseNumbersAndFillContainer(char **arr, int ac);
		containerVector				sortVector(containerVector& vector);
		containerDeque				sortDeque(containerDeque& deque);

		IndexedVector				sortVectorIndexed(IndexedVector& vec);
		void						comparePairsIndexed(IndexedPairVector& pairVec,
											IndexedVector& smaller,
											IndexedVector& bigger);


		IndexedDeque				sortDequeIndexed(IndexedDeque& deq);
		void						comparePairsIndexed(IndexedPairDeque& pairVec,
											IndexedDeque& smaller,
											IndexedDeque& bigger);

											
		containerVector				_vector;
		std::deque<unsigned int>	_deque;
		size_t						_vectorComparisons;
		size_t						_dequeComparisons;

	public:
		PmergeMe();
		PmergeMe(char** arr, int ac);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void	runSort();

};

unsigned int	countDigits(unsigned int n);
void			printNewline();

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

double					getTimeUsec(void);
std::vector<ssize_t>	getJacobsIndex(size_t smallerSizeIn);


#endif /* PmergeMe_HPP */