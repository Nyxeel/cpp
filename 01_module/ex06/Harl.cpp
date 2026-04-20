/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:26:37 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 19:31:28 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() { std::cout << "Harl constructed" << std::endl; }

Harl::~Harl() { std::cout << "Harl destructed" << std::endl; }

void Harl::debug() {
  std::cout << "[ DEBUG ]" << "\n";
  std::cout << "I love having extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger ";
  std::cout << "I really do!" << std::endl;
}

void Harl::info() {
  std::cout << "[ INFO ]" << "\n";
  std::cout << "I cannot believe adding extra bacon costs more money. ";
  std::cout << "You didn't put enough bacon in my burger! ";
  std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
  std::cout << "[ WARNING ]" << "\n";
  std::cout << "I think I deserve to have some extra bacon for free. ";
  std::cout << "I've been coming for years, whereas you started ";
  std::cout << "working here just last month." << std::endl;
}

void Harl::error() {
  std::cout << "[ ERROR ]" << "\n";
  std::cout << "This is unacceptable! I want to speak to the manager now.";
  std::cout << std::endl;
}

int Harl::levelToIndex(std::string level) {
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (levels[i] == level)
      return (i);
  }
  return (-1);
}

void Harl::complain(std::string level) {
  switch (levelToIndex(level)) {
  case 0:
    Harl::debug();
    // fall through
  case 1:
    Harl::info();
    // fall through
  case 2:
    Harl::warning();
    // fall through
  case 3:
    Harl::error();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]";
    std::cout << std::endl;
  }
  return;
}
