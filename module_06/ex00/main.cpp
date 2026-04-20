# include "ScalarConverter.hpp"



int	main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "invalid number of args" << std::endl;
		std::cerr << "usage: ./program_name \"argument\"" << std::endl;	
	}
	ScalarConverter::convert(av[1]);

	return (0);
}