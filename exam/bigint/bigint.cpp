/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 12:37:50 by pjelinek          #+#    #+#             */
/*   Updated: 2026/08/20 01:16:11 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <string>
#include <sstream>



bigint::bigint()
{

	std::stringstream ss;
	ss << 0;
	this->str = ss.str();
	// std::cout << this->str << std::endl;
}

bigint::bigint(unsigned int value)
{

	std::stringstream ss;
	ss << value;
	this->str = ss.str();

	// std::cout << this->str << std::endl;
}

bigint::bigint(const bigint &other) : str(other.str)
{

	// std::cout << this->str << std::endl;
}

bigint& bigint::operator=(const bigint& other) {

	if (this != &other) {

		this->str = other.str;
	}
	return(*this);
}

bigint::~bigint()
{
}

const std::string &bigint::getStr() const
{

	return (this->str);
}

std::ostream &operator<<(std::ostream &out, const bigint &other)
{

	out << other.getStr();
	return out;
}


std::string reverse(const std::string &str) {

	std::string revStr;
	for (size_t i = str.length(); i > 0; i--) {

		revStr.push_back(str[i - 1]);
	}
	return(revStr);
}

std::string	addition(const bigint& obj1, const bigint& obj2) {

	std::string str1 = reverse(obj1.getStr());
	std::string str2 = reverse(obj2.getStr());
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	if (len1 < len2) {

		size_t diff = len2 - len1;
		while (diff > 0) {
			str1.push_back('0');
			diff--;
		}
	}
	else if (len2 < len1) {

		size_t diff = len1 - len2;
		while (diff > 0) {
			str2.push_back('0');
			diff--;
		}
	}

	int carry = 0;
	int num1;
	int num2;
	std::string result;
	size_t len = str1.length();

	for(size_t i = 0; i < len; i++) {

		num1 = str1[i] - '0';
		num2 = str2[i] - '0';

		int res = num1 + num2 + carry;

		if (res > 9) {

			carry = res / 10;
			result.push_back((res % 10) + '0');
		}
		else
		{
			carry = 0;
			result.push_back(res + '0');
		}
	}
	if (carry != 0)
		result.push_back(carry + '0');
	return(reverse(result));
}

bigint bigint::operator+(const bigint& other) const {

	bigint result;

	result.str = addition(*this, other);
	return result;
}

bigint& bigint::operator+=(const bigint& other) {

	bigint result;

	result = *this + other;
	*this = result;
	return *this;
}

// pre increment
bigint&	bigint::operator++() {

	*this = *this + bigint(1);
	return *this;

}

//post incerment
bigint	bigint::operator++(int) {

	bigint result = *this;

	*this = *this + bigint(1);
	return result;

}

bool	bigint::operator>(const bigint& other) const {

	int len1 = this->str.length();
	int len2 = other.getStr().length();

	if (len1 != len2)
		return (len1 > len2);
	return (this->str > other.getStr());
}

bool	bigint::operator<(const bigint& other) const {

	int len1 = this->str.length();
	int len2 = other.getStr().length();

	if (len1 != len2)
		return (len1 < len2);
	return (this->str < other.getStr());
}

bool	bigint::operator<=(const bigint& other) const {

	return *this == other || *this < other;
}
bool	bigint::operator>=(const bigint& other) const {

	return *this == other || *this > other;
}
bool	bigint::operator==(const bigint& other) const {

	return this->getStr() == other.getStr();
}
bool	bigint::operator!=(const bigint& other) const {

	return this->getStr() != other.getStr();
}


bigint bigint::operator<<(unsigned int n) const {

	bigint tmp = *this;

	if (tmp.str == "0")
    	return tmp;
	tmp.str.insert(tmp.str.end(), n ,'0');
	return tmp;

}

bigint bigint::operator>>(unsigned int n) const {

	bigint tmp = *this;

	if (n >= tmp.str.length())
		tmp.str = "0";
	else
		tmp.str.erase(tmp.str.length() - n , n);
	return tmp;
}

bigint& bigint:: bigint::operator<<=(unsigned int n) {

	*this = *this << n;
	return *this;

}

bigint& bigint::operator>>=(unsigned int n) {

	*this = *this >> n;
	return *this;
}

unsigned int stringToUINT(std::string str) {

	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return res;
}



bigint bigint::operator<<(const bigint& other) const {

	bigint tmp;

	tmp = *this << stringToUINT(other.str);
	return tmp;


}

bigint bigint::operator>>(const bigint& other) const {

	bigint tmp;

	tmp = *this >> stringToUINT(other.str);
	return tmp;

}

bigint& bigint::bigint::operator<<=(const bigint& other) {

	*this = *this << stringToUINT(other.str);
	return *this;

}

bigint& bigint::operator>>=(const bigint& other) {

	*this = *this >> stringToUINT(other.str);
	return *this;

}

