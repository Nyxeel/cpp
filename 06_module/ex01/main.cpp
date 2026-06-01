/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:04:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 17:20:29 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data	data;

	data.name = "Test";
	data.value = 42;

	std::string testName = data.name;
	int testValue = data.value;

	uintptr_t num = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(num);

	if (testName == ptr->name && testValue == ptr->value && &data == ptr)
		std::cout << "Test Valid" << std::endl;
	else
		std::cout << "Test Failed" << std::endl;
	return 0;
}
