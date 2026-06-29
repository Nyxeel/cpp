/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:15:16 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/29 14:43:06 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

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

template<typename T>
typename T::const_iterator	easyfind(const T& container, int num) {

	typename T::const_iterator it;
	typename T::const_iterator begin = container.begin();
	typename T::const_iterator end = container.end();

	it = std::find(begin, end, num);
	if (it != end)
		return it;
	throw NotFoundException();
}