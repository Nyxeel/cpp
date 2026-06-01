/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 00:52:48 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 19:48:25 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BASE_HPP
#define	BASE_HPP


class Base
{
	public:
		virtual ~Base();


};

Base*	generate(void);
void 	identify(Base* p);
void	identify(Base& p);


#endif /* BASE_HPP */
