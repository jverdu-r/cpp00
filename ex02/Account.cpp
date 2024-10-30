/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:27:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/10/30 10:27:57 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void){return;}

Account& Account::operator=(Account const& origin)
{
    this->_nbAccounts= origin._nbAccounts;
	this->_totalAmount= origin._totalAmount;
	this->_totalNbDeposits= origin._totalNbDeposits;
	this->_totalNbWithdrawals= origin._totalNbWithdrawals;
    this->_accountIndex = origin._accountIndex;
    this->_amount = origin._amount;
	this->_nbDeposits = origin._nbDeposits;
	this->_nbWithdrawals = origin._nbWithdrawals;
    return (*this);
}

int Account::getNbAccounts(void){return (Account::_nbAccounts);}

int Account::getTotalAmount(void){return (Account::_totalAmount);}

int Account::getNbDeposits(void){return (Account::_totalNbDeposits);}

int Account::getNbWithdrawals(void){return (Account::_totalNbWithdrawals);}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm *time = std::localtime(&now);
    std::cout << "[";
    std::cout << 1900 + time->tm_year;
    std::cout << std::setw(2) << std::setfill('0') << time->tm_mday;
    std::cout << "-";
    std::cout << std::setw(2) << std::setfill('0') << time->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << time->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << time->tm_sec;
    std::cout << "]";
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed:" << std::endl;
    return;
}

Account::Account(int initial_deposit)
{
    _nbDeposits = 0;
	_nbWithdrawals = 0;
    _accountIndex = Account::_nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created:" << std::endl;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    std::cout << "withdrawal:" << withdrawal << ";";
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    std::cout << "not using?!!!" << std::endl;
    return (1);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}


