/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:04:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/02 05:00:34 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void	printArr(T* arr, int length){

	for(int i = 0; i < length; i++){
		std::cout << arr[i] << std::endl;
	}
}

void	printNewline(){
	std::cout << std::endl;
}

void	incrementAscii(char& c){
	if (c == 126)
		c = 33;
	else
		c += 1;
}

void	plusTen(int& num){
	num += 10;
}

template <typename T>
void	printValue(T& value){
	std::cout << value << std::endl;
}

int main()
{
 	char		arrChar[5] = {'A', 'B', 'C', 'D', 'E'};

	std::cout << "\033[32mTEST #1 - Increment Ascii value for arrChar[5]\033[0m" << std::endl << "OLD:" << std::endl;

	printArr(arrChar, 5);
	printNewline();

	::iter(arrChar, 5, incrementAscii);

	std::cout << "NEW:" << std::endl;
	printArr(arrChar, 5);
	printNewline();

	//////////////////////////////////////////////////

	int			arrInt[5] = {32, 212, 89, 153, 625};

	std::cout << "\033[32mTEST #2 - num + 10 for arrInt[5]\033[0m" << std::endl << "OLD:" << std::endl;
	printArr(arrInt, 5);
	printNewline();

	::iter(arrInt, 5, plusTen);

	std::cout << "NEW: + 10" << std::endl;
	printArr(arrInt, 5);
	printNewline();

	/////////////////////////////////////////////////

	const std::string arrString[5] = {"Anita", "Bob", "Christian", "Doris", "Emil"};
	std::cout << "\033[32mTEST #3 - print strings from const arrString\033[0m" << std::endl;

	::iter(arrString, 5, printValue);
	printNewline();

	return 0;
}
