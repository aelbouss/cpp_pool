

#include  "Harl.hpp"



void    Harl::debug( void )
{
    std::cout<< GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
    << "ketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::infos( void )
{
    std::cout<< GREEN << "I cannot believe adding extra bacon costs more money. You didn't put"
    << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void    Harl::warning( void )
{
    std::cout << GREEN <<"I think I deserve to have some extra bacon for free. I've been coming for"
    << "years, whereas you started working here just last month." << RESET << std::endl;
}

void    Harl::error ( void )
{
    std::cout << GREEN <<"This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void    Harl::complain( std::string level )
{
    void    (Harl::*lvlpointer[])(void) = {&Harl::debug, &Harl::infos, &Harl::warning , &Harl::error};
    std::string levels[] = {"DEBUG", "INFOS", "WARNING", "ERROR"};
    int option = -1;
    for(int i = 0 ; i < 4 ; i++)
    {
        if (level == levels[i])
        {
            option = i;
            break ;
        }
    }
    switch (option)
    {
        case 0 :
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*lvlpointer[0])();
            /* fall through */
        case 1 :
            std::cout << "[ INFOS ]" << std::endl;
            (this->*lvlpointer[1])();
            /* fall through */
        case 2 :
             std::cout << "[ WARNING ]" << std::endl;
            (this->*lvlpointer[2])();
            /* fall through */
        case 3 :
             std::cout << "[ ERROR ]" << std::endl;
            (this->*lvlpointer[3])();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}