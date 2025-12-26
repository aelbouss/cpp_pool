# include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	Energy_points = 100;
	Attack_dammage = 30;
}

FragTrap&	FragTrap::operator = (const FragTrap& src)
{
	if (this == &src)
		return (*this);
	this->hit_points = src.hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_dammage = src.Attack_dammage;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& src) 
{
	this->hit_points = src.hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_dammage = src.Attack_dammage;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap says High Fives" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}