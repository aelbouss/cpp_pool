# include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	BitcoinEngine;

	if (ac != 2)
	{
		std::cerr << RED << "Invalid Arguments Number"<< RESET << std::endl; return (1);
	}
	if (!BitcoinEngine.parse_db_file(av[1]))
		return -1;

	return (0);
}

