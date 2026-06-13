/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:58:43 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/13 21:06:40 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <climits>



Span::Span(unsigned int N) : maxStore(N) {

}

Span::Span(const Span &other) : maxStore(other.maxStore), container(other.container) {

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

void	Span::addMultipleNumbers(std::vector<int>::iterator begin,
		std::vector<int>::iterator end) {

	for (; begin != end; begin++) {

		this->addNumber(*begin);
	}
}

int	Span::shortestSpan() const {


	if (container.size() <= 1)
		throw NoSpanException();

	std::vector<int> tmp = container;
	std::vector<int>::iterator begin = tmp.begin();
	std::vector<int>::iterator end = tmp.end();
	std::vector<int>::iterator next = begin + 1;

	int span = INT_MAX;
	int distance;

	std::sort(begin, end);

	for(; begin != end; begin++) {

		if (next != end)
			distance = *next - *begin ;
		if (distance < span)
			span = distance;

		next++;
	}
	return span;
}


int	Span::longestSpan() const {


	if (container.size() <= 1)
		throw NoSpanException();

	std::vector<int>::const_iterator begin = container.begin();
	std::vector<int>::const_iterator end = container.end();

	int min = *std::min_element(begin, end);
	int max = *std::max_element(begin, end);

	return max - min;
}