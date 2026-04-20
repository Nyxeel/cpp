/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:33:10 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 19:21:45 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl h;

	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("INFO");

	h.complain("NOT_FOUND");
	return (0);
}