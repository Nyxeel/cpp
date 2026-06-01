/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:04:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 06:37:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	if (ac != 2){
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
