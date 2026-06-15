/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:19:03 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/15 22:43:46 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <exception>
#include <string>

#define WHITESPACES " \t\n"

class BitcoinExchange {

	private:

		std::map<std::string, double>		database;
		void	loadDatabase();

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	processData(std::string str);
		double	getPrice(std::string& key);

	class CouldNotOpenFileException : public std::exception {

		public:
			const char* what() const throw();
	};

	typedef typename std::map<std::string, double>::iterator iterator;

};

//void print(std::string str);

#endif /* BITCOINEXCHANGE_HPP */