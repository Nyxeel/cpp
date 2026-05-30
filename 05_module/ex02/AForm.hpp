/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:11:44 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/30 20:32:19 by pjelinek         ###   ########.fr       */
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
		virtual void		executeAction() const = 0;

	public:
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm() = 0;

		// signing and executing
		void				beSigned(const Bureaucrat &other);
		void 				execute(Bureaucrat const &executor) const;

		//getter
		const std::string	getName() const;
		bool 				getSignedStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		//Exception classes
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
		class	FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &other);

#endif /* AFORM_HPP */