/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:33:31 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/13 23:35:23 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

void	printNewline() {

	std::cout << std::endl;
}

template <typename Iter>
void	printRange(Iter begin, Iter end) {

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}

int	main(void)
{
	{
		// TEST 1: Subject example
		std::cout << "\033[32mTest #1 : Subject example \033[0m" << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		printRange(it, ite);
		std::stack<int> s(mstack);
	}

	printNewline();

	{
		// TEST 2: Copy constructor
		std::cout << "\033[32mTest #2 : Copy constructor \033[0m" << std::endl;

		MutantStack<int> original;
		original.push(10);
		original.push(20);
		original.push(30);

		MutantStack<int> copy(original);

		printRange(copy.begin(), copy.end());
		original.push(999);
		std::cout << "copy size: " << copy.size() << " (should be 3)" << std::endl;
	}

	printNewline();

	{
		// TEST 3: Assignment operator
		std::cout << "\033[32mTest #3 : Assignment operator \033[0m" << std::endl;

		MutantStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);

		MutantStack<int> b;
		b.push(99);
		b = a;

		printRange(b.begin(), b.end());
		std::cout << "b size: " << b.size() << " (should be 3)" << std::endl;
	}

	printNewline();

	{
		// TEST 4: Different type (std::string)
		std::cout << "\033[32mTest #4 : MutantStack<std::string> \033[0m" << std::endl;

		MutantStack<std::string> mstack;
		mstack.push("hello");
		mstack.push("world");
		mstack.push("42");

		std::cout << "top: " << mstack.top() << std::endl;
		printRange(mstack.begin(), mstack.end());
	}

	printNewline();

	{
		// TEST 5: Compare output with std::list (same traversal order expected)
		std::cout << "\033[32mTest #5 : Compare output with std::list \033[0m" << std::endl;

		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		std::cout << "MutantStack: ";
		MutantStack<int>::iterator mit = mstack.begin();
		while (mit != mstack.end())
		{
			std::cout << *mit << " ";
			++mit;
		}
		std::cout << std::endl;

		std::cout << "std::list:   ";
		std::list<int>::iterator lit = lst.begin();
		while (lit != lst.end())
		{
			std::cout << *lit << " ";
			++lit;
		}
		std::cout << std::endl;
	}

	printNewline();

	{
		// TEST 6: const_iterator on a const MutantStack
		std::cout << "\033[32mTest #6 : const_iterator on const MutantStack \033[0m" << std::endl;

		MutantStack<int> tmp;
		tmp.push(7);
		tmp.push(14);
		tmp.push(21);

		const MutantStack<int> cmstack(tmp);

		printRange(cmstack.begin(), cmstack.end());
	}

	return (0);
}
