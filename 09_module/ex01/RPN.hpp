/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:34:49 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/16 20:02:36 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <list>

#define SPACE 32

class RPN {

	typedef std::stack<double, std::list<double> > st;

	private:
		st		stack;
		void	calcRPN(const std::string& str);


	public:
		RPN(const std::string& str);
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		double	executeCalc(char c);
		double	add(double a, double b);
		double	substract(double a, double b);
		double	divide(double a, double b);
		double	multiply(double a, double b);

};


#endif /* RPN_HPP */