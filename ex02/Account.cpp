/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:13:21 by lorey             #+#    #+#             */
/*   Updated: 2025/02/13 16:12:47 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

////////////////////////////////////////////////////////
//here we have static variable independant of objects//
////////////////////////////////////////////////////////

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;



void Account::_displayTimestamp()
{
    std::time_t now = std::time(nullptr);
    std::tm* tm = std::localtime(&now);
    std::cout << "[" << (tm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (tm->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << tm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << tm->tm_hour
              << std::setw(2) << std::setfill('0') << tm->tm_min
              << std::setw(2) << std::setfill('0') << tm->tm_sec
              << "] ";
}

//////////////////////////////////////
// here we just have classic getters//
//////////////////////////////////////

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

///////////////////////////////////////////////////////////////
//here we display the timestamp and then the static variables//
///////////////////////////////////////////////////////////////

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

/////////////////////////////////////////////////////////
//here is the constructor it already setup             //
//_accountIndex with static _nbAccount and             //
//_amout with initial_deposit                          //
//it also increment the nb account and the total amount//
//(and write created)                                  //
/////////////////////////////////////////////////////////

Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts), _amount(initial_deposit),
    _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

////////////////////////////////////////
//the destructor only write closed    //
//with the correct index and the amout//
////////////////////////////////////////

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

/////////////////////////////
//I think the code is clear//
/////////////////////////////

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount - deposit << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (_amount < withdrawal)
	{
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";"
                  << "p_amount:" << _amount << ";"
                  << "withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount + withdrawal << ";"
              << "withdrawal:" << withdrawal << ";"
              << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals
              << std::endl;
}

