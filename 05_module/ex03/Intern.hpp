/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:57:51 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/01 00:44:22 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		typedef AForm* (*FormCreator)(const std::string& target);

	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(const std::string	&formName, const std::string &target);

		class	FormNotExisting : public std::exception
		{
			public:
				const char* what() const throw();
		};
};


#endif /* INTERN_HPP */