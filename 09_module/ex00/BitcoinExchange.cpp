/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:19:03 by pjelinek          #+#    #+#             */
/*   Updated: 2026/06/15 22:44:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "iostream"
#include "fstream"
#include <iomanip>

BitcoinExchange::BitcoinExchange() {

	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	database(other.database) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {

	if (this != &other) {

		database = other.database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {

}

const char* BitcoinExchange::CouldNotOpenFileException::what() const throw() {

	return("Error: Cannot open file");
}

int	moveIdx(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

bool trim(std::string& str)
{
	size_t	endIdx;
	size_t	startIdx;
	size_t	len;

	startIdx = 0;

	while (moveIdx(WHITESPACES, str[startIdx]) != 0)
		startIdx++;
	endIdx = str.length();
	if (!endIdx)
		return false;
	while (moveIdx(WHITESPACES, str[endIdx - 1]))
		endIdx--;
	if (startIdx > endIdx)
		return (false);
	len = endIdx - startIdx;
	str = str.substr(startIdx, len);
	return true;
}

bool	parseDateFormat(std::string& key) {

	for(size_t idx = 0; key[idx]; idx++) {

		if (!std::isdigit(key[idx])) {

			if(key[idx] == '-' && (idx == 4 || idx == 7))
				continue;
			return false;
		}
	}
	static int daysPerMonth[12] =
			{31, 28, 31 , 30, 31, 30, 31, 31, 30, 31 ,30 , 31};


	int month = atoi(key.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int day = atoi(key.substr(8, 2).c_str());
	if (day < 1 || day > daysPerMonth[month - 1])
		return false;
	return true;
}

bool	isValidLeapYear(int year, int month, int day) {

	if (month != 2)
		return false;
	if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return false;
	if (day > 29)
		return false;
	return (true);
}

bool	parseDate(std::string& key) {

	if (!trim(key))
		return (false);

	for(size_t idx = 0; key[idx]; idx++) {

		if (!std::isdigit(key[idx])) {

			if(key[idx] == '-' && (idx == 4 || idx == 7))
				continue;
			return false;
		}
	}
	static int daysPerMonth[12] =
			{31, 28, 31 , 30, 31, 30, 31, 31, 30, 31 ,30 , 31};

	int year = atoi(key.substr(0, 4).c_str());
	if (year < 2009)
		return false;
	int month = atoi(key.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return false;

	int day = atoi(key.substr(8, 2).c_str());
	if (day < 1 || day > daysPerMonth[month - 1]){

		if (isValidLeapYear(year, month, day))
			return true;
		return false;
	}
	return true;
}

bool	parseExchangeRate(std::string value) {

	if (!trim(value))
		return false;

	size_t comma = 0;
	for(size_t idx = 0; value[idx]; idx++) {

		if (value[idx] == '.' && comma < 1) {

			comma++;
			continue;
		}
		if (!std::isdigit(value[idx])) {
			return false;
		}
	}
	return true;
}

void	BitcoinExchange::loadDatabase() {

	// open file
	std::ifstream data("data.csv");
	if(!data) {
		throw CouldNotOpenFileException();
	}

	// read file
	std::string key;
	std::string exchangeRate;
	std::string line;

	while (std::getline(data, line)) {

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		key = line.substr(0, comma);
		exchangeRate = line.substr(comma + 1);

		if (!parseDate(key) || !parseExchangeRate(exchangeRate)) {
			continue;
		}

		char *endptr;
		double value = strtod(exchangeRate.c_str(), &endptr);
		this->database[key] = value;

		//std::cout << std::setprecision(15) << key << " " << value << std::endl;
	}
}

double	BitcoinExchange::getPrice(std::string& date) {

	if (database.find(date) == database.end()) {

		iterator it = database.upper_bound(date);
		if (it == database.begin())
			return (-1);
		else {

			it--;
			return (it->second);
		}
	}
	return (database[date]);
}

void	BitcoinExchange::processData(std::string str) {

	std::ifstream data(str.c_str());
	if(!data) {
		throw CouldNotOpenFileException();
	}

	std::string date;
	std::string rightPart;
	std::string line;

	while (std::getline(data, line)) {

		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {

			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		} //

		date = line.substr(0, pipe);
		rightPart = line.substr(pipe + 1);

		if (!parseDate(date)){
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		char *endptr;
		double bitcoins = strtod(rightPart.c_str(), &endptr);

		if (bitcoins < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (bitcoins > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		double price = getPrice(date);
		if (price == -1){
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::cout << std::setprecision(2) << date << " => " << bitcoins
		<< " = " << price * bitcoins << std::endl;

	}

}