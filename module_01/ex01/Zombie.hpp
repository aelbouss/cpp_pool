# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	Name;
	public:
		Zombie();
    	void    announce ( void );
		Zombie	*zombieHorde( int N, std::string name );
		void	set_name(std::string name);
		~Zombie();
};

Zombie	*zombieHorde( int N, std::string name );

# endif