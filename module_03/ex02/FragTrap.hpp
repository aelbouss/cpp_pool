# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include  "ScavTrap.hpp"

class	FragTrap : public ClapTrap	
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap&	operator = (const FragTrap& src);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
		FragTrap(const FragTrap& src);
		~FragTrap();
};

#endif