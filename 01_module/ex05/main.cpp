/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:33:10 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/09 19:54:34 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"
#include <iostream>

int main()
{
	Harl h;

	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("ERROR");


	h.complain("INFO");


	return (0);
}