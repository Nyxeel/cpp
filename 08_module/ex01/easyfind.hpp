/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:15:16 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/12 13:33:48 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>

template<typename T>
typename T::iterator	easyfind(T& container, int num);

template<typename T>
typename T::const_iterator	easyfind(const T& container, int num);

class NotFoundException : public std::exception {

	public:
		const char* what() const throw ();
};

#include "easyfind.tpp"

#endif