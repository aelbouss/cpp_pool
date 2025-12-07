#include "Harl.hpp"

void    Harl::debug( void )
{
    std::cout<< GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
    << "ketchup burger. I really do!" << std::endl;
}

void	Harl::infos( void )
{
    std::cout<< GREEN << "I cannot believe adding extra bacon costs more money. You didn't put"
    << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << GREEN <<"I think I deserve to have some extra bacon for free. I've been coming for"
    << "years, whereas you started working here just last month." << std::endl;
}

void    Harl::error ( void )
{
    std::cout << GREEN <<"This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    void    (Harl::*lvlpointer)(void) ;

    if (level.empty())
    {
        std::cerr << RED <<"empty input !"<< std::endl;
    }
    else if (level == "DEBUG")
    {
        lvlpointer = &Harl::debug;
        (this->*lvlpointer)();
    }
    else if (level == "INFOS")
    {
        lvlpointer = &Harl::infos;
        (this->*lvlpointer)();
    }
    else if (level == "WARNING")
    {
        lvlpointer = &Harl::warning;
        (this->*lvlpointer)();
    }
    else if (level == "ERROR")
    {
        lvlpointer = &Harl::error;
        (this->*lvlpointer)();
    }
    else
    {
        std::cerr << RED << "invalid complain level !" << std::endl;
        std::cerr << RED << "the available complain levels are : DEBUG , INFOS , WARNING , ERROR" << std::endl;
    }
}