/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:14:12 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/20 17:30:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include <Fixed.hpp>

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point& operator=(const Point &other);
		~Point();


};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif