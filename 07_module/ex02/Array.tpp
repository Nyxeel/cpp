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

#include "Array.hpp"

tempalte <typename T>
Array::Array() {

	Array arr = new T;	//ALLOCATE WITH NEW ?
	size = 0;
}


tempalte <typename T>
Array::Array(unsigned int n) {

	 Array<T> arr = new Array[n];
	 size = n;
}

tempalte <typename T>
Array::Array(const Array &other) : arr(new T(other.size)), size(other.size) {

	 arr
}