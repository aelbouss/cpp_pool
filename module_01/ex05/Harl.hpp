# ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class	Harl
{
	private:
		void	debug( void );
		void	infos( void );
		void	warning( void );
		void	error ( void ) ;
	public:
		void	complain( std::string level );
};

# define RED   "\033[0;31m"
# define GREEN "\033[0;32m"

# endif