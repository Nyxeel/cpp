/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:11:44 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/29 16:15:06 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			signGrade;
		const int 			execGrade;
		bool				isSigned;

	public:
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm() = 0;

		void				beSigned(const Bureaucrat &other);

		const std::string	getName() const;
		bool 				getSignedStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;


		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
/* 		class	AFormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		}; */
};

std::ostream& operator<<(std::ostream &out, const AForm &other);

#endif /* AFORM_HPP */