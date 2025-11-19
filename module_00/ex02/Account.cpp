/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:39:09 by aelbouss          #+#    #+#             */
/*   Updated: 2025/11/19 23:39:10 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts( void ) { return (_nbAccounts); }

int	Account::getTotalAmount( void ) { return (_totalAmount); }


int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }

int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

int		Account::checkAmount( void ) const { return (_amount); }

void	Account::_displayTimestamp( void )
{
    std::time_t curr_time = std::time(0);
    std::tm *local_time = localtime(&curr_time);

    std::cout << "[" << (local_time ->tm_year + 1900);
    std::cout << std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1);
    std::cout << std::setw(2) << std::setfill('0') << (local_time->tm_mday);
    std::cout << '_';
    std::cout << std::setw(2) << std::setfill('0') << (local_time->tm_hour);
    std::cout << std::setw(2) << std::setfill('0') << (local_time->tm_min);
    std::cout << std::setw(2) << std::setfill('0') << (local_time->tm_sec);
    std::cout << "] ";
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:"<< getNbAccounts() << ';';
    std::cout << "total:" << getTotalAmount() << ';';
    std::cout << "deposits:"<< getNbDeposits() << ';';
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( const int deposit ) 
{
    int p_amount;

    p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
     _displayTimestamp();
    std::cout << "index:"<<_accountIndex << ';';
    std::cout << "p_amount:" << p_amount << ';';
    std::cout << "deposit:" << deposit << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_deposits:" << _nbDeposits << std::endl; 
}

bool	Account::makeWithdrawal( const int withdrawal ) 
{
   int p_amount;

    p_amount = _amount;
    _displayTimestamp();
    std::cout << "index:"<<_accountIndex << ';';
    std::cout << "p_amount:" << p_amount << ';';
    if ((_amount - withdrawal) <  0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (true);
    }
    _nbWithdrawals++ ;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

Account::Account( const int initial_deposit )
{
    _displayTimestamp();
    _amount = initial_deposit;
	_accountIndex = _nbAccounts++;
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created" << std::endl;
    _totalAmount += _amount ;
}

Account::~Account( void )
{
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed" << std::endl;
    _totalAmount = _totalAmount - _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}