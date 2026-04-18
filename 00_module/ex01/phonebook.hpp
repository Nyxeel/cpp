/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:32:58 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/11 19:33:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstring>
#include "contacts.hpp"

class PhoneBook
{

	private:
		Contact 	contacts[8];
		std::string formatString(std::string name);
		int			checkNumber(std::string input);
		void		printContact();
		void		printPhonebook();
		int			currIndex;
		int			currContacts;
		int			index;

	public:
		PhoneBook();
		~PhoneBook();

		void		AddContact();
		void		SearchContact();
};

#endif