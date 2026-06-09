/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 00:58:28 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 17:31:09 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


#include <ctime>
#include <cstdlib>
#include <iostream>

Base::~Base(){
	std::cout << "Base destructor called" << std::endl;
}

Base*	generate(void){

	Base *random = NULL;

	int num = rand() % 100;
	if (num % 3 == 0)
		random = new A();
	else if (num % 3 == 1)
		random = new B();
	else
		random = new C();
	return random;
}

A*	getAPtr(Base *p){

	return dynamic_cast<A*>(p);
}

B*	getBPtr(Base *p){

	return dynamic_cast<B*>(p);
}

C*	getCPtr(Base *p){

	return dynamic_cast<C*>(p);
}

void 	identify(Base* p){

	if (getAPtr(p) != NULL)
		std::cout << "A" << std::endl;
	else if (getBPtr(p) != NULL)
		std::cout << "B" << std::endl;
	else if (getCPtr(p) != NULL)
		std::cout << "C" << std::endl;
}


A&	getARef(Base& p){

	return dynamic_cast<A&>(p);
}

B&	getBRef(Base& p){

	return dynamic_cast<B&>(p);
}

C&	getCRef(Base& p){

	return dynamic_cast<C&>(p);
}

void	identify(Base& p){

	try{
		getARef(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...){	}

	try{
		getBRef(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...){	};

	try{
		getCRef(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...){	};
}
