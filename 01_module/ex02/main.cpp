/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/12 18:13:34 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

int main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	std::cout << "var\t" << var << std::endl;
	std::cout << "&var\t" << &var << std::endl;
	std::cout << "var[0]\t" << var[0] << std::endl;

	std::cout << std::endl;

	std::cout << "*stringPTR\t" << *stringPTR << std::endl;
	std::cout << "stringPTR\t" << stringPTR << std::endl;
	std::cout << "&stringREF\t" << &stringREF << std::endl;

	return (0);
}
