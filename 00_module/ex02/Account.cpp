/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:54:39 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 13:55:45 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	std::cout << "Account class default constructed" << std::endl;
}

Account::Account(int deposit)
	: _accountIndex(_nbAccounts), _amount(deposit)
{
 	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created" << std::endl;
	_totalAmount += deposit;
	_nbAccounts++;
}


Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *t = std::localtime(&now);

    char buffer[18]; // "[YYYYMMDD_HHMMSS]" + '\0' = 18
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", t);

    std::cout << buffer;
}

int Account::checkAmount() const
{
	return (_amount);
}



int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}


void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << checkAmount() + deposit << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits += _nbDeposits;
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
}


bool Account::makeWithdrawal ( int withdrawal)
{
	_nbWithdrawals++;


	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		_nbWithdrawals--;
		_totalNbWithdrawals += _nbWithdrawals;
		return (false);
	}
	std::cout << withdrawal << ";";
	std::cout << "amount:" << checkAmount() - withdrawal << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalNbWithdrawals += _nbWithdrawals;
	_amount -= withdrawal;
	_totalAmount = _totalAmount - withdrawal;
	return (true);
}



void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
	std::cout << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}