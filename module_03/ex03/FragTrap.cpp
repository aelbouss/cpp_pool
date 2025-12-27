# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std::cout << BLUE << "FragTrap constructor  called " << RESET << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& src)
{
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (hit_points == 0)
	{
		std::cout << this->Name << RED << "is dead" << RESET << std::endl;
		return;
	}
	if (Energy_points == 0)
	{
		std::cout << RED << "0 Energy Points"<< RESET << std::endl;
		return ;
	}
	std::cout<< YELLOW << "FragTrap's over  power is  coming ... "<< RESET << std::endl;
	std::cout << RED << "FragTrap "<< YELLOW << this->Name << RED << " attacks "<< YELLOW << target << RED << " , causing "
		<< hit_points << " Points of damage HHHHHH" << RESET<< std::endl;
	this->Energy_points--;
}

FragTrap::FragTrap(const FragTrap& src) :ClapTrap(src)
{
	std::cout << "Copy Constructor of FragTrap Called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "FragTrap : High Fives" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "FragTrap Destructor Called"<< RESET << std::endl;
}