# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }


ScalarConverter& ScalarConverter::operator = (const ScalarConverter& src) { (void)src; return *this;}


 ScalarConverter::~ScalarConverter() {}

bool	check_for_printables(std::string str)
{
	for (size_t i = 0 ; i  <  str.size() ; i++)
	{
		if (!std::isprint(static_cast<unsigned char>(str[i])))
		{
			std::cerr << "Non displayable" << std::endl;
			return false;
		}
	}
	return (true);
}


void	char_check(double nbr)
{
	
	if (nbr < 0 || nbr > 127 || std::isnan(nbr) || std::isinf(nbr))
	{
		std::cout << "char : impossible" << std::endl;
		return ;
	}
	if (!std::isprint(static_cast<int>(nbr)))
	{
		std::cout << "char: Non displayable"<< std::endl;
		return ;
	}
	std::cout << "char : "<< static_cast<char>(nbr) << std::endl;
}

void	check_int(double nbr)
{
	if (std::isnan(nbr) || std::isinf(nbr))
	{
		std::cerr << "int : impossible" << std::endl;
		return ;
	}
	if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
	{
		std::cerr << "int : impossible" << std::endl;
		return ;
	}
	std::cout << "int : "<< static_cast<int>(nbr) << std::endl;
}


void	check_float(double nbr)
{

	if(std::isinf(nbr))
	{
		if (nbr < 0)
			std::cerr << "float : -inff" << std::endl;
		if (nbr > 0)
			std::cerr << "float : inff" << std::endl;
		return ;
	}
	if ( std::isnan(nbr) )
	{
		std::cout << "float : nanf" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float : " << static_cast<float>(nbr) << 'f' << std::endl;
}

void	check_double(double nbr)
{
	
	if(std::isinf(nbr))
	{
		if (nbr < 0)
			std::cerr << "doubel : -inf" << std::endl;
		if (nbr > 0)
			std::cerr << "double : inf" << std::endl;
		return ;
	}
	if (std::isnan(nbr))
	{
		std::cout << "double : nan" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double : " << nbr << std::endl;
}

void	ScalarConverter::convert(const std::string& str)
{
	char	*endpts;
	double nbr;

	if (!check_for_printables(str))
		return ;
	if (str.size() == 1 && !std::isdigit(str[0]))
		nbr = static_cast<double>(str[0]);
	else
		nbr = strtod(str.c_str(), &endpts);
	if (*endpts == 'f' && *(endpts + 1) != 0)
	{
		std::cerr << "invalid input" << std::endl;
		return ;
	}
	char_check(nbr);
	check_int(nbr);
	check_float(nbr);
	check_double(nbr);
}