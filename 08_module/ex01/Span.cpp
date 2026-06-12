/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:58:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/12 14:14:25 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : maxStore(N){

}

Span::Span(const Span &other) : maxStore(other.maxStore) {

}

Span&	Span::operator=(const Span &other) {

	if (this != &other)
		maxStore = other.maxStore;
	return(*this);
}

Span::~Span() {

}

void	addNumber(int num) {

}

void	addMultipleNumbers() {

}

int	shortestSpan() {

	int span = 0;

	return span;
}


int	longestSpan() {

	int span = 0;

	return span;
}