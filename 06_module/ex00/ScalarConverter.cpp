/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 00:58:28 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 18:25:01 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void) other;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &other){
	(void) other;
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter destructor called" << std::endl;
}


int	detectType(const std::string &str){

	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR_TYPE;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (PSEUDO_FLOAT);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (PSEUDO_DOUBLE);

	int		comma = 0;
	int 	fchar = 0;
	size_t 	idx = 0;
	int 	num = 0;

	if (str[0] == '+' || str[0] == '-')
		idx = 1;
	for(size_t i = idx; i < str.length(); i++){

		if (str[i] == '.'){
			comma++;
			continue ;
		}
		if (str[i] == 'f' && i == str.length() - 1){
			fchar++;
			continue ;
		}
		if (!std::isdigit(str[i]))
			return INVALID;
		num++;
	}
	if (comma == 1 && fchar == 1 && num >= 2)
		return FLOAT_TYPE;
	if (comma == 1 && num >= 2)
		return DOUBLE_TYPE;
	if (num >= 1 && comma == 0 && fchar == 0)
		return INT_TYPE;
	return INVALID;
}

/* void	printType(int type){
	if (type == CHAR_TYPE)
		std::cout << "CHAR Type " << std::endl;
	else if (type == INT_TYPE)
		std::cout << "INT Type " << std::endl;
	else if (type == FLOAT_TYPE)
		std::cout << "FLOAT Type " << std::endl;
	else if (type == DOUBLE_TYPE)
		std::cout << "DOUBLE Type " << std::endl;
	else if (type == PSEUDO_FLOAT)
		std::cout << "PSEUDO_FLOAT Type " << std::endl;
	else if (type == PSEUDO_DOUBLE)
		std::cout << "PSEUDO_DOUBLE Type " << std::endl;
	else
		std::cout << "INVALID Type " << std::endl;
} */

void	printChar(double num){
	if (num >= 0 && (num < 32 || num == 127))
		std::cout << "char: Non displayable" << std::endl;
	else if (num > 127 || num < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(num) << "\'" <<  std::endl;
}


void	printInt(double num, int errorCode){

	if (errorCode == ERANGE || num < INT_MIN || num > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

void	printFloat(double num, int errorCode){

	if (errorCode == ERANGE || num < -FLT_MAX || num > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else if (std::floor(num) == num)
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
}

void	printDouble(double num, int errorCode){

	if (errorCode == ERANGE) //overflow at 10^308 !!
		std::cout << "double: impossible" << std::endl;
	else if (std::floor(num) == num)
		std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	ScalarConverter::convert(const std::string &str){

	if (str.empty())
		return ;
	int type = detectType(str);

	//printType(type); //debug

	if (type == INVALID){
		std::cout << "Conversion for \"" << str << "\" not possible" << std::endl;
		return;
	}

	if (type == CHAR_TYPE)
	{
		char c = str[0];
		std::cout << "char: \'" << c << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(c)  << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
	}

	else if (type == INT_TYPE || type == FLOAT_TYPE || type == DOUBLE_TYPE)
	{
		char *endptr;
		int errorCode;
		double num = std::strtod(str.c_str(), &endptr);
		errorCode = errno;

		printChar(num);
		printInt(num, errorCode);
		printFloat(num, errorCode);
		printDouble(num, errorCode);
	}
	else if (type == PSEUDO_DOUBLE || type == PSEUDO_FLOAT)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nan" || str == "nanf"){
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (str == "-inf" || str == "-inff"){
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else if (str == "+inf" || str == "+inff"){
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
	}

}