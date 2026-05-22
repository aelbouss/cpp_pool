# include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
    BitcoinExchange	BitcoinEngine;    
    
    (void)av;
    (void)ac;
	/*if (ac != 2)
	{
		std::cerr << RED << "Invalid Arguments Number"<< RESET << std::endl; return (1);
	}*/
    try
    {
    	BitcoinEngine.parse_db_file();
    }
    catch (std::exception & e)
    {
        std::cout << "Exception Caught : " << e.what() << std::endl; 
    }
	return (0);
}


