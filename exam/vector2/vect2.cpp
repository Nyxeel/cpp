/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:02:56 by pjelinek          #+#    #+#             */
/*   Updated: 2026/08/20 17:11:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : num1(0), num2(0) {

}

vect2::vect2(int num1, int num2) : num1(num1), num2(num2) {


}

vect2::vect2(const vect2& other) : num1(other.num1), num2(other.num2) {

}

vect2& vect2::operator=(const vect2& other) {

	if (this == &other)
		return *this;
	this->num1 = other.num1;
	this->num2 = other.num2;
	return *this;
}

vect2::~vect2() {

}

int	vect2::operator[](int index) const {

	if (index == 0)
		return (this->num1);
	return (this->num2);
}

int&	vect2::operator[](int index) {

	if (index == 0)
		return (this->num1);
	return (this->num2);
}



std::ostream& operator<<(std::ostream& out, const vect2& other) {

	out << "{" << other[0] << ", " << other[1] << "}" ;
	return out;
}

vect2&	vect2::operator++() {

	this->num1 += 1;
	this->num2 += 1;

	return *this;
}

vect2	vect2::operator++(int) {

	vect2 tmp = *this;
	this->num1 += 1;
	this->num2 += 1;

	return tmp;
}

vect2&	vect2::operator--() {

	this->num1 -= 1;
	this->num2 -= 1;

	return *this;
}

vect2	vect2::operator--(int) {

	vect2 tmp = *this;
	this->num1 -= 1;
	this->num2 -= 1;

	return tmp;
}

bool	vect2::operator==(const vect2& other) const {

	return this->num1 == other.num1 && this->num2 == other.num2;
}

bool	vect2::operator!=(const vect2& other) const {

	return this->num1 != other.num1 || this->num2 != other.num2;
}

vect2	vect2::operator+(const vect2& other) const {

	vect2 tmp;

	tmp.num1 = this->num1 + other.num1;
	tmp.num2 = this->num2 + other.num2;

	return tmp;
}

vect2&	vect2::operator+=(const vect2& other) {

	this->num1 += other.num1;
	this->num2 += other.num2;
	return *this;
}


vect2	vect2::operator-(const vect2& other) const {

	vect2 tmp;

	tmp.num1 = this->num1 - other.num1;
	tmp.num2 = this->num2 - other.num2;

	return tmp;
}

vect2&	vect2::operator-=(const vect2& other) {

	this->num1 -= other.num1;
	this->num2 -= other.num2;
	return *this;
}

vect2	vect2::operator*(int scalar) const {

	vect2 tmp;

	tmp.num1 = this->num1 * scalar;
	tmp.num2 = this->num2 * scalar;

	return tmp;
}

vect2&	vect2::operator*=(int scalar) {

	this->num1 *= scalar;
	this->num2 *= scalar;
	return *this;
}

vect2	operator*(int scalar, const vect2& obj) {

	vect2 tmp;

	tmp[0] = obj[0] * scalar;
	tmp[1] = obj[1] * scalar;

	return tmp;
}

vect2	vect2::operator-() const {

	vect2 tmp;

	tmp.num1 = -this->num1;
	tmp.num2 = -this->num2;

	return tmp;
}



