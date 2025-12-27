# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap :public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap&	operator = (const ScavTrap& src);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};

# endif