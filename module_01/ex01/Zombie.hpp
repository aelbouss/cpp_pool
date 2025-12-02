# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <limits>
# include <cstdlib>

class	Zombie
{
	private:
		std::string	Name;
	public:
		Zombie();
    	void    announce ( void );
		void	set_name(std::string name);
		~Zombie();
};

Zombie	*zombieHorde( int N, std::string name );

# define GREEN "\033[0;32m"
# define RED   "\033[0;31m"
# define RESET "\033[0m"

# endif