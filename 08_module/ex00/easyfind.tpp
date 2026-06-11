/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:15:16 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/11 23:13:52 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

const char*		NotFoundException::what() const throw(){

	return ("Number not found in container.");
}

template<typename T>
typename T::iterator	easyfind(T& container, int num) {

	typename T::iterator it;
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();

	it = std::find(begin, end, num);
	if (it != end)
		return it;
	throw NotFoundException();
}