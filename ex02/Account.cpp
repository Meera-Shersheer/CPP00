/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:49:57 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/26 03:09:39 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}	

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" <<_nbAccounts << ";total:"<< _totalAmount <<";deposits:"
	<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals <<std::endl;

}
Account::Account( void )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:"<< _amount <<";created"<<std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:"<< _amount <<";closed"<<std::endl;

}

void Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_totalNbDeposits++;	
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";p_amount:"<< _amount << ";deposit:"<< deposit;
	_amount += deposit;
	std::cout <<";amount:"<< _amount <<";nb_deposits:" << _nbDeposits <<std::endl;
}
bool Account::makeWithdrawal( int withdrawal )
{

	if (_amount >= withdrawal)
	{
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" <<_accountIndex << ";p_amount:"<< _amount << ";withdrawal:"<< withdrawal;
		_amount -= withdrawal;
		std::cout <<";amount:"<< _amount <<";nb_withdrawals:" << _nbWithdrawals <<std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" <<_accountIndex << ";p_amount:"<< _amount << ";withdrawal:refused" <<std::endl;
		return (false);
	}
}
int	Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:"<< _amount 
	<<";deposits:" << _nbDeposits<< ";withdrawals:"<< _nbWithdrawals<<std::endl;

}

void	Account::_displayTimestamp( void )
{
	std::time_t time;
	std::tm *time_h;

	time = std::time(NULL);
	time_h = localtime(&time);
	std::cout<< std::setfill('0') <<"[" << std::setw(4) << time_h->tm_year + 1900
	<< std::setw(2) << time_h->tm_mon + 1 << std::setw(2) <<
	time_h->tm_mday<< "_" << std::setw(2) << time_h->tm_hour << 
	std::setw(2) << time_h->tm_min << std::setw(2) << time_h->tm_sec << "] ";
}




