/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:06:29 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/25 17:03:07 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

int main(void)
{
  PhoneBook phonebook;
  std::string input;

  std::cout << "Welcome to the PhoneBook!" << "\n";
  while (1) {
    std::cout << "Please enter ADD, SEARCH or EXIT!" << "\n";
    if (!std::getline(std::cin, input))
      break;
    if (input == "ADD")
      phonebook.AddContact();
    else if (input == "SEARCH")
      phonebook.SearchContact();
    else if (input == "EXIT")
      break;
  }
  return (0);
}
