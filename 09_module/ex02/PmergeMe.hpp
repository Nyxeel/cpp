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

class PmergeMe {

	typedef double time;

	private:

		void						parseNumbersAndFillContainer(char **arr, int ac);
		std::vector<unsigned int>&	sortVector(std::vector<unsigned int> vector);
		std::deque<unsigned int>&	sortDeque(std::deque<unsigned int> deque);
		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;

	public:
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