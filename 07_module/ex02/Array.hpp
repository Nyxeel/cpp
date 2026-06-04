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

template <typename T>
class Array {

	private:

		T*				arr;
		unsigned int	size;


	public:
		Array();
		Array(unsigned int n);
};


#endif /* ARRAY_HPP */