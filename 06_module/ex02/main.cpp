/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:04:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 20:00:35 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand (time(NULL));

	Base *a = generate();

	identify(a);	//PTR
	identify(*a);	//REF

	delete a;
	return 0;
}
