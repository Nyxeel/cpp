/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:02:56 by pjelinek          #+#    #+#             */
/*   Updated: 2026/08/20 17:10:39 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_HPP
#define VECT_HPP

#include <ostream>

class vect2 {

	private:

		int	num1;
		int	num2;

	public:
		vect2();
		vect2(int num1, int num2);
		vect2(const vect2& other);
		~vect2();

		vect2&	operator=(const vect2& other);

		int		operator[](int index) const;
		int&	operator[](int index);

		vect2&	operator++();		// pre
		vect2	operator++(int); 	// post

		vect2&	operator--();		// pre
		vect2	operator--(int); 	// post

		bool	operator==(const vect2& other) const;
		bool	operator!=(const vect2& other) const;

		vect2	operator+(const vect2& other) const;
		vect2&	operator+=(const vect2& other);
		vect2	operator-(const vect2& other) const;
		vect2&	operator-=(const vect2& other);
		vect2	operator*(int scalar) const;
		vect2&	operator*=(int scalar);
		vect2	operator-() const;

};

vect2 operator*(int scalar, const vect2& obj);

std::ostream& operator<<(std::ostream& out, const vect2& other);


#endif