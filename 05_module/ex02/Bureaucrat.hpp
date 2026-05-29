/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:11:44 by pjelinek          #+#    #+#             */
/*   Updated: 2026/05/29 16:10:20 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;

	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		int					getGrade() const;
		const std::string	getName() const;
		int					increaseGrade();
		int					decreaseGrade();

		void 				signForm(AForm &form);

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
};


std::ostream& operator<<(std::ostream &out, const Bureaucrat &other);

#endif /* BUREAUCRAT_HPP */