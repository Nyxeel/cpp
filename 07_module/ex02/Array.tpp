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

template <typename T>
Array<T>::Array() : arr(NULL), arrSize(0)
{
	//default constructor
}

template <typename T>
Array<T>::Array(unsigned int n) {

	arr = new T[n];
	arrSize = n;
}

template <typename T>
Array<T>::Array(const Array<T> &other) :
	arr(other.arrSize > 0 ? new T[other.arrSize] : NULL), arrSize(other.arrSize)
{
		if (arr){

			for(unsigned int i = 0; i < arrSize; i++) {
				this->arr[i] = other.arr[i];
			}
		}
		//copy constructor
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T> &other){

	if (this != &other) {

		if (arr)
			delete[] arr;
		arr = other.arrSize > 0 ? new T[other.arrSize] : NULL;
		arrSize = other.arrSize;
		if (arr)
			for(unsigned int i = 0; i < arrSize; i++) {

				this->arr[i] = other.arr[i];
			}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
unsigned int Array<T>::size() const {

	return (arrSize);
}

template <typename T>
const char*	Array<T>::IndexOutOfBounds::what() const throw() {

	return ("Index out of bounds");
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index){

	if (index >= arrSize)
		throw IndexOutOfBounds();
	return arr[index];
}