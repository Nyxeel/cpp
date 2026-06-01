/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 00:52:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 17:29:37 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
		~Serializer();

	public:
		static uintptr_t 	serialize(Data *ptr);
		static Data* 		deserialize(uintptr_t raw);

};

#endif /* SERIALIZER_HPP */
