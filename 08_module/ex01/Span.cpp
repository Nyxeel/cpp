/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:58:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/29 14:52:00 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <climits>



Span::Span(unsigned int N) : maxStore(N) {

}

Span::Span(const Span &other) :
	maxStore(other.maxStore), container(other.container) {

}

Span&	Span::operator=(const Span &other) {

	if (this != &other) {

		maxStore = other.maxStore;
		container = other.container;
	}
	return(*this);
}

Span::~Span() {

}

std::vector<int> Span::getContainer() {

	return (this->container);
}

const char*	Span::MaxStoreException::what() const throw() {

	return("Cant add more numbers - Reached maximun capacity for container");
}

const char*	Span::NoSpanException::what() const throw() {

	return("There is no span to calculate in container (elements <= 1)");
}

void	Span::addNumber(int num) {

	if (container.size() >= maxStore)
		throw MaxStoreException();
	container.push_back(num);
}

void	Span::addMultipleNumbers(
			std::vector<int>::iterator begin,
			std::vector<int>::iterator end) {

	if (container.size() + std::distance(begin, end) > maxStore)
		throw MaxStoreException();

	container.insert(container.end(), begin, end);
}

double	Span::shortestSpan() const {


	if (container.size() <= 1)
		throw NoSpanException();

	std::vector<int> tmp = container;
	std::vector<int>::iterator begin = tmp.begin();
	std::vector<int>::iterator end = tmp.end();
	std::vector<int>::iterator next = begin + 1;

	double span = LLONG_MAX;

	std::sort(begin, end);

	for(; next != end; begin++, next++) {

		double distance = *next - *begin ;
		if (distance < span)
			span = distance;
	}
	return span;
}


double	Span::longestSpan() const {


	if (container.size() <= 1)
		throw NoSpanException();

	std::vector<int>::const_iterator begin = container.begin();
	std::vector<int>::const_iterator end = container.end();

	double min = *std::min_element(begin, end);
	double max = *std::max_element(begin, end);

	return max - min;
}