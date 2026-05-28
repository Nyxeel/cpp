/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:11:44 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/29 00:03:14 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <exception>

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		int					signingGrade;
		int 				excuteGrade;

	public:
		Form(const std::string name, int grade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		void beSigned(const Bureaucrat &other);

		class	GradeTooLow : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooHigh : public std::exception
		{
			const char* what() const throw();
		};
};


std::ostream& operator<<(std::ostream &out, const Form &other);

#endif /* FORM_HPP */