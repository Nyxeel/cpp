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

#include <vector>
#include <deque>
#include <cstddef>
#include <utility>


typedef std::vector<unsigned int> containerVector;
typedef std::deque<unsigned int> containerDeque;

// Wert + eindeutige Ursprungs-ID; die ID wandert beim Sortieren automatisch mit
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

		// rekursiver Ford-Johnson-Kern + Paarvergleich, arbeiten auf indizierten Werten (vector)
		IndexedVector				sortVectorIndexed(IndexedVector& vec);
		void						comparePairsIndexed(IndexedPairVector& pairVec,
											IndexedVector& smaller,
											IndexedVector& bigger);

		// dasselbe fuer deque
		IndexedDeque					sortDequeIndexed(IndexedDeque& deq);
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

template <typename T>
void		printContainer(T container);

double	getTimeUsec(void);


#endif /* PmergeMe_HPP */