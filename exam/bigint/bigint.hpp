/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 12:37:50 by pjelinek          #+#    #+#             */
/*   Updated: 2026/08/20 01:15:40 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP
#include <string>
#include <ostream>


class bigint {

	private:

		std::string str;


	public:

		bigint();
		bigint(unsigned int value);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);

		~bigint();

		const std::string& getStr() const;

		bigint	operator+(const bigint& other) const;
		bigint&	operator+=(const bigint& other);

		bigint&	operator++();
		bigint	operator++(int);

		bool	operator<(const bigint& other) const;
		bool	operator>(const bigint& other) const;
		bool	operator<=(const bigint& other) const;
		bool	operator>=(const bigint& other) const;
		bool	operator==(const bigint& other) const;
		bool	operator!=(const bigint& other) const;

		bigint  operator<<(unsigned int n) const;
		bigint  operator>>(unsigned int n) const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		bigint  operator<<(const bigint& other) const;
		bigint  operator>>(const bigint& other) const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);


};

std::ostream& operator<<(std::ostream& out, const bigint& other);


#endif
