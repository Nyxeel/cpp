/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 03:00:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 04:57:34 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <exception>

template <typename T>
class Array {

	private:

		T*				arr;
		unsigned int	arrSize;


	public:

		Array();
		Array(unsigned int size);
		Array(const Array &other);
		Array&	operator=(const Array &other);
		~Array();

		T&	operator[](const unsigned int index);
		unsigned int	size() const;

		class IndexOutOfBounds : public std::exception {

			public:
				const char* what() const throw();
		};
};

#include "Array.tpp"


#endif /* ARRAY_HPP */