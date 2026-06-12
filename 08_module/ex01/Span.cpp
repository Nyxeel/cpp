/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:58:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/12 22:05:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>


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

const char*	Span::MaxStoreException::what() const throw() {

	return("Reached maximun capacity for container");
}

const char*	Span::NoSpanException::what() const throw() {

	return("There is no span to calculate in container (elements <= 1)");
}

void	Span::addNumber(int num) {

	if (container.size() >= maxStore)
		throw MaxStoreException();
	container.push_back(num);
}

void	addMultipleNumbers() {

}

int	Span::shortestSpan() {


	if (container.size() <= 1)
		throw NoSpanException();

	std::vector<int> tmp = container;
	std::vector<int>::iterator begin = tmp.begin();
	std::vector<int>::iterator end = tmp.end();
	int span = INT_MAX;

	std::sort(begin, end);

	for(; begin != end; begin++) {

		int distance = std::distance(begin, begin + 1);
		if (distance < span)
			span = distance;
	}
	return span;
}


int	Span::longestSpan() {


	if (container.size() <= 1)
		throw NoSpanException();

	std::vector<int> tmp = container;
	std::vector<int>::iterator begin = tmp.begin();
	std::vector<int>::iterator end = tmp.end();
	int span = 0;

	std::sort(begin, end);

	for(; begin != end; begin++) {

		int distance = std::distance(begin, begin + 1);
		if (distance > span)
			span = distance;
	}
	return span;
}