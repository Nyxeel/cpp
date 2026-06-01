/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 00:52:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 06:04:25 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cerrno>
#include <cstdlib>
#include <cfloat>
#include <climits>
#include <cmath>


enum {
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void	convert(const std::string &str);

};

#endif /* SCALARCONVERTER_HPP */
