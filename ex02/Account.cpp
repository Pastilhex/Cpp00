/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:49:06 by ialves-m          #+#    #+#             */
/*   Updated: 2023/12/04 19:19:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	char buffer[80];
	std::time_t timestamp = std::time(NULL);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", std::localtime(&timestamp));
	std::cout << buffer;
}

int		Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}


int 	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int		Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void )
{
	return *(this->_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";amount:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount -= withdrawal < 0)
		return false;
	return true;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::getNbAccounts() << ";amount:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	std::cout << "index:" << Account::getNbAccounts() << ";p_amount:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_amount += initial_deposit;
}

Account::~Account( void ) {};