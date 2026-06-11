/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:33:31 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/11 22:56:26 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <vector>
// #include <list>
// #include <deque>
#include <iostream>


int	main(void)
{
	std::vector<int>	a = {1 , 2 ,3 ,4 };
	// std::list<int>		b;
	// std::deque<int>		c;

	std::vector<int>::iterator it = a.begin();
	std::vector<int>::reverse_iterator rev = a.rbegin();
	a.insert(it, 9);



	try{
		easyfind(a, 54);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	return (0);
}