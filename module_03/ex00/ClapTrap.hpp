# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
		std::string Name;
		int hit_points; // health of  the  claptrap 
		int	Energy_points;
		int Attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		ClapTrap&	operator = (const ClapTrap& src);
		void	attack(const std::string& target);
		void	takeDammage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		~ClapTrap();
};

# define RESET "\033[0m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"


# endif