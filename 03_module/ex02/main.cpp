/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/19 19:37:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n FragTrap Construction \n";
    FragTrap frag("Fraggy");

    std::cout << "\n FragTrap Attack \n";
    frag.attack("Target1");
    frag.attack("Target2");

    std::cout << "\n FragTrap High Five \n";
    frag.highFivesGuys();

    std::cout << "\n FragTrap HP TESTt (Start 100) \n";
    frag.takeDamage(40);
    frag.beRepaired(10);

    std::cout << "\n FragTrap Copy Constructor \n";
    FragTrap copied(frag);
    copied.attack("CopyTarget");
    copied.highFivesGuys();

    std::cout << "\n FragTrap Copy assignment \n";
    FragTrap assigned("Temp");
    assigned = frag;
    assigned.attack("AssignedTarget");
    assigned.highFivesGuys();

    std::cout << "\n FragTrap Destruction \n";
    return 0;
}

