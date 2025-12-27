#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
	Name = "Nothing";
	hit_points = 0;
	Energy_points = 0;
	Attack_damage = 0;
	std::cout << BLUE << "ScavTrap's Default Constructor Called " << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
	std::cout << BLUE << "ScavTrap's Parameterized Constructor Called " << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap's copy constructor called" << std::endl;
	*this = src;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& src)
{
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_points == 0)
	{
		std::cout << this->Name << RED << " is dead" << RESET << std::endl;
		return;
	}
	if (Energy_points == 0)
	{
		std::cout << RED << "0 Energy Points"<< RESET << std::endl;
		return ;
	}
	std::cout<< YELLOW << "The over power is coming ..."<< RESET << std::endl;
	std::cout << RED << "ScavTrap "<< YELLOW << this->Name << RED << " attacks "<< YELLOW << target << RED << " , causing "
		<< hit_points << " Points of damage  yeaaaaa" << RESET<< std::endl;
	this->Energy_points--;
}

void	ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap " << Name << " now in gate keeper mode" << RESET <<  std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap's Destructor Called"<< RESET << std::endl;
}