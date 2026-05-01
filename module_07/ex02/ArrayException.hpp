# ifndef ARRAYEXCEPTION_HPP
# define ARRAYEXCEPTION_HPP

# include <iostream>
# include <string>
# include <exception>


class	ArrayException : public  std::exception
{
	public:
		const char	*what() const throw() ;
};
# endif