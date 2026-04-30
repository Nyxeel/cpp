/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:00 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/01 01:26:58 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
  std::string var = "HI THIS IS BRAIN";
  std::string *stringPTR = &var;
  std::string &stringREF = var;

  std::cout << "Memory adress of var\t\t" << &var << "\n";
  std::cout << "Memory adress of var\t\t" << stringPTR << "\n";
  std::cout << "Memory adress of stringPTR\t" << &stringPTR << "\n";
  std::cout << "Memory adress of stringREF = var\t\t" << &stringREF << "\n";

  std::cout << "\n";
  std::cout << "Value of var\t\t" << var << "\n";
  std::cout << "value of stringPTR\t" << *stringPTR << "\n";
  std::cout << "Value of stringREF\t" << stringREF << std::endl;

  return (0);
}
