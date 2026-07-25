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
typedef std::pair<unsigned int, size_t> TaggedUint;

typedef std::vector<TaggedUint> taggedVector;
typedef std::vector<std::pair<TaggedUint, TaggedUint> > taggedPairVector;

typedef std::deque<TaggedUint> taggedDeque;
typedef std::deque<std::pair<TaggedUint, TaggedUint> > taggedPairDeque;

class PmergeMe {

	typedef double time;

	private:

		void						parseNumbersAndFillContainer(char **arr, int ac);
		containerVector				sortVector(containerVector& vector);
		containerDeque				sortDeque(containerDeque& deque);

		// rekursiver Ford-Johnson-Kern + Paarvergleich, arbeiten auf getaggten Werten (vector)
		taggedVector				sortVectorTagged(taggedVector& vec);
		void						comparePairsTagged(taggedPairVector& pairVec,
											taggedVector& smaller,
											taggedVector& bigger);

		// dasselbe fuer deque
		taggedDeque					sortDequeTagged(taggedDeque& deq);
		void						comparePairsTagged(taggedPairDeque& pairVec,
											taggedDeque& smaller,
											taggedDeque& bigger);

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