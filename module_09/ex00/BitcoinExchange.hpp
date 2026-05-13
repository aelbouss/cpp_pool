# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>

class	BitcoinExchange
{

	public:
		BitcoinExchange();
		BitcoinExchange&	operator = (const BitcoinExchange& src);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
};

# endif