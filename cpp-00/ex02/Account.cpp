#include  "Account.hpp"



// recreate the lost file which is Account.hpp
// check the header file Account.hpp to check the missed functions
// check the  log  file  to  usedrtand hoe  the  class ACCount was implimented
// learn about the   variable  very  good .

// getters :

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	displayTimestamp( void )
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
    std::cout << ']';
}

void	Account::displayAccountsInfos( void )
{
    displayTimestamp();
    std::cout << " ";
    std::cout << "accounts:"<<_nbAccounts << ';';
    std::cout << "total:" << _totalAmount << ';';
    std::cout << "deposits:"<< _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( const int deposit ) { _amount += deposit; }

bool	Account::makeWithdrawal( const int withdrawal ) { _amount -= withdrawal; }

int		Account::checkAmount( void ) const { return (_amount); }

Account::Account( const int initial_deposit )
{
    displayTimestamp();
    _amount = initial_deposit;
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
     displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed" << std::endl;
}

void	Account::displayStatus( void ) const
{
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals" << _nbWithdrawals << std::endl;
}