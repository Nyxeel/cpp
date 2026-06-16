/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:34:49 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/16 20:50:57 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>


RPN::RPN(const std::string& str){

	calcRPN(str);
}

RPN::RPN(const RPN &other) : stack(other.stack) {

}

RPN& RPN::operator=(const RPN &other){

	if (this != &other) {

		stack = other.stack;
	}
	return (*this);
}

RPN::~RPN() {

}

double	RPN::add(double a, double b) {

	return(a + b);
}

double	RPN::substract(double a, double b) {

	return(a - b);
}

double	RPN::divide(double a, double b) {

	if (b == 0)
		throw std::runtime_error("Error");
	return(a / b);
}

double	RPN::multiply(double a, double b) {

	return(a * b);
}

double RPN::executeCalc(char c)
{
	double b = stack.top();	stack.pop();
	double a = stack.top(); stack.pop();

	double (RPN::*fn[4])(double, double) = { &RPN::add, &RPN::substract, &RPN::divide, &RPN::multiply };
	char action[4] = {'+', '-', '/', '*'};

	for (int i = 0; i < 4; i++) {
		if (action[i] == c)
		{
			return ((this->*fn[i]) (a, b));
		}
	}
	throw std::runtime_error("Error: calc function not found");
}


void	RPN::calcRPN(const std::string& str) {


	const std::string	OPERATOR = "+-/*";
	double idx;

	for (size_t i = 0; i < str.length(); i++) {

		if (str[i] == SPACE)
			continue;

		else if ((OPERATOR.find(str[i])) != std::string::npos) {

			idx = OPERATOR.find(str[i]);
			if (stack.size() < 2)
				throw std::runtime_error("Error: unused operator");

			double result = executeCalc(OPERATOR[idx]);
			stack.push(result);

		}
		else if(isdigit(str[i]) && str[i + 1] == SPACE) {

			double num = str[i] - '0';
			stack.push(num);
		}
		else
			throw std::runtime_error("Error: Invalid char");

	}
	if (stack.size() != 1 )
		throw std::runtime_error("Error");

	std::cout << stack.top() << std::endl;
}



