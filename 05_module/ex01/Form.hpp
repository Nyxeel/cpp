/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:11:44 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/29 03:51:05 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		int					signGrade;
		int 				execGrade;
		bool				isSigned;

	public:
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		void				beSigned(const Bureaucrat &other);

		const std::string	getName() const;
		bool 				getSignedStatus() const;
		int 				getSignGrade() const;
		int 				getExecGrade() const;


		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class	FormAlreadySignedException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Form &other);

#endif /* FORM_HPP */