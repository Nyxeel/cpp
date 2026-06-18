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

#include <string>
#include <vector>
#include <deque>

class PmergeMe {

	typedef double time;

	private:

		void				parseNumbersAndFillContainer(char **arr, int ac);
		void				sortVector();
		void				sortDeque();
		std::vector<int>	_vector;
		std::deque<int>		_deque;

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