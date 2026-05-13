# include "BitcoinExchange.hpp"


int	main(int ac, char **av)
{

	void(ac) , (av);
	std::ifstream csv_database("./data.csv");
	if (!csv_database.is_open())
	{
		std::cerr << "Error : couldn't open the database file" << std::endl;
		return (-1);
	}
	csv_database.close();
	
	return (0);
}