/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.Utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sys/time.h>
#include <iostream>


double	getTimeUsec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec * 1000000.0 + (double)tv.tv_usec);
}

unsigned int countDigits(unsigned int n)
{
	unsigned int count = 1;

	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return count;
}

void	print(std::string str) {

	std::cout  << str;
}

void	printNewline() {

	std::cout  << std::endl;
}

template <typename T>
void	printPairs(T& pairVec) {

	typename T::iterator begin = pairVec.begin();
	typename T::iterator end = pairVec.end();
	for(; begin != end; begin++ ) {

		std::cout 	<< "First: " << begin->first
					<< " Second: " <<  begin->second
					<< std::endl;
	}
}


// gets the jacobsthal indizes for a certain size!!
std::vector<ssize_t>	getJacobsIndex(size_t smallerSizeIn) {

	std::vector<ssize_t> arr;

	ssize_t smallerSize = smallerSizeIn;
	//if smaller is only one num, then push it to index 0
	if (smallerSize == 1) {

		arr.push_back(0);
		return (arr);
	}

	ssize_t prev0 = 0;
	ssize_t prev1 = 1;
	ssize_t jacobsBorderNum = 0;

	//calc the jacobthal indexes until size_t smallerSizeIn
	while (smallerSize >= jacobsBorderNum) {

		jacobsBorderNum = prev1 + 2 * prev0; 	// Jacobs Num Calc
		if (jacobsBorderNum <= smallerSize)
			arr.push_back(jacobsBorderNum - 1);

		ssize_t tmp = jacobsBorderNum;
		while (tmp > prev1) {

			tmp -= 1;
			if (tmp <= smallerSize && tmp != prev1)
				arr.push_back(tmp - 1);
		}
		prev0 = prev1;
		prev1 = jacobsBorderNum;
	}
	return arr;
}
