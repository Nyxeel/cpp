/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/09 20:08:22 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	std::cout << "var\t" << var << "\n";
	std::cout << "&var\t" << &var << "\n";

	std::cout << "\n";

	std::cout << "*stringPTR\t" << *stringPTR << "\n";
	std::cout << "stringPTR\t" << stringPTR << "\n";
	std::cout << "stringREF\t" << stringREF << "\n";
	std::cout << "&stringREF\t" << &stringREF << std::endl;

	return (0);
}
