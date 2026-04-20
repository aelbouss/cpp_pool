# ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <limits>
# include <iomanip>
# include <iomanip>
# include <cctype>
# include <cmath>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator = (const ScalarConverter& src);
		~ScalarConverter();
	public:
		static	void	convert(const std::string& str);	
};

bool	check_for_printables(std::string str);


# endif