/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 03:00:54 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 04:57:34 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// Non-const
template <typename T>
void	iter(T* arr, const size_t arrLength, void (*f)(T&)){

	for (size_t i = 0; i < arrLength; i++){
		(*f)(arr[i]);
	}
}

//Const
template <typename T>
void	iter(const T* arr, const size_t arrLength, void (*f)(const T&)){

	for (size_t i = 0; i < arrLength; i++){
		(*f)(arr[i]);
	}
}


#endif /* ITER_HPP */