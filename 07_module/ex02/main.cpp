/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:04:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/10 03:27:02 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>


template <typename T>
void	printArr(T& arr, unsigned int size){

	for(unsigned int i = 0; i < size; i++){
		std::cout << "a[" << i << "]: " << arr[i] << std::endl;
	}
}

void	printNewline(){
	std::cout << std::endl;
}

int main()
{

	std::cout << "\033[32mTest #1 : Try to acces arr with out-of-bounds index a[1] \033[0m" << std::endl;
	try{
		Array<int> a;
		std::cout << a[1] << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	printNewline();
	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #2 : Int array \033[0m" << std::endl;
	try{
		Array<int> a(5);

		a[0] = 10;
		a[1] = 20;
		a[2] = 30;
		a[3] = 40;
		a[4] = 50;

		std::cout << a[1] << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #3 : String array \033[0m" << std::endl;
	try{
		Array<std::string> a(5);

		a[0] = "Wir";
		a[1] = "Wollen";
		a[2] = "Wenig";
		a[3] = "Wäsche";
		a[4] = "Waschen";

		printArr(a, 5);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #4 : Copy constructor (same text)\033[0m" << std::endl;
	try{
		Array<std::string> a(5);

		a[0] = "Wir";
		a[1] = "Wollen";
		a[2] = "Wenig";
		a[3] = "Wäsche";
		a[4] = "Waschen";

		Array<std::string> b(a);

		printArr(b, 5);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}


	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #5 : Assignment operator (same text) \033[0m" << std::endl;
	try{
		Array<std::string> a(5);

		a[0] = "Wir";
		a[1] = "Wollen";
		a[2] = "Wenig";
		a[3] = "Wäsche";
		a[4] = "Waschen";

		Array<std::string> b;
		b = a;

		printArr(b, 5);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #6 : index == arrSize \033[0m" << std::endl;
	try{
		Array<std::string> a(5);

		a[0] = "Wir";
		a[1] = "Wollen";
		a[2] = "Wenig";
		a[3] = "Wäsche";
		a[4] = "Waschen";

		std::cout << a[5] << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #7 : print size for Array a[5]; \033[0m" << std::endl;
	try{
		Array<std::string> a(5);

		a[0] = "Wir";
		a[1] = "Wollen";
		a[2] = "Wenig";
		a[3] = "Wäsche";
		a[4] = "Waschen";

		std::cout << "Size: " << a.size() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #8 : Test for const Array with operator b[2] \033[0m" << std::endl;
	try{
		Array<std::string> a(5);

		a[0] = "Wir";
		a[1] = "Wollen";
		a[2] = "Wenig";
		a[3] = "Wäsche";
		a[4] = "Waschen";

		const Array<std::string> b(a);
		std::cout << "b[2]: " << b[2] << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}


	////////////////////////////////////////////////

	printNewline();
	std::cout << "\033[32mTest #9 : print out arr values when they are not explicitly set\033[0m" << std::endl;
	try{
		Array<int> a(5);
		printArr(a, 5);
		// because of arr(new T[n]() ) in constructor values are 0 for int!!
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}


	printNewline();
	return 0;
}

