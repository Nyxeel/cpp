/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:58:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/29 17:08:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {

	private:
		unsigned int 		maxStore;
		std::vector<int> 	container;

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void	addNumber(int num);

		void	addMultipleNumbers(std::vector<int>::iterator begin,
								std::vector<int>::iterator end);

		long	shortestSpan() const;
		long	longestSpan() const;

		std::vector<int> getContainer();

		class MaxStoreException : public std::exception {

			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception {

			public:
				const char* what() const throw();
		};
};



#endif /* SPAN_HPP */