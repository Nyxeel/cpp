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


typedef std::vector<std::pair<unsigned int, unsigned int> > pairVector;
typedef std::deque<std::pair<unsigned int, unsigned int> > pairDeque;
typedef std::vector<unsigned int> containerVector;
typedef std::deque<unsigned int> containerDeque;

class PmergeMe {

	typedef double time;

	private:

		void						parseNumbersAndFillContainer(char **arr, int ac);
		containerVector				sortVector(containerVector& vector);
		containerDeque				sortDeque(containerDeque& deque);
		void						comparePairs(pairVector& pairVec,
											std::vector<unsigned int>& smaller,
											std::vector<unsigned int>& bigger);

		void						comparePairs(pairDeque& pairVec,
											std::deque<unsigned int>& smaller,
											std::deque<unsigned int>& bigger);

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