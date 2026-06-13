/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:58:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/13 21:06:40 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template <typename T>
MutantStack<T>::MutantStack(){

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) :
	std::stack<T>(other) {

}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T> &other) {

	if (this != &other) {

		std::stack<T>::operator=(other);
	}
	return(*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {

}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {

	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {

	return (this->c.end());
}