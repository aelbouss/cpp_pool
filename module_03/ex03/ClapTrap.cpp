# include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : Name(name) 
{
	hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
	std::cout << BLUE << "Constructor Called"<< RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points == 0)
	{
		std::cout << this-> Name << RED << " is dead" << RESET << std::endl;
		return;
	}
	if (Energy_points == 0)
	{
		std::cout << RED << "0 Energy Points"<< RESET << std::endl;
		return ;
	}
	std::cout << RED << "ClapTrap "<< YELLOW << this->Name << RED << " attacks "<< YELLOW << target << RED << " , causing "
		<< hit_points << " Points of damage" << RESET<< std::endl;
	this->Energy_points--;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& src)
{
	if (this == &src)
		return (*this);
	this->Name = src.Name;
	this->hit_points = src.hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	this->Name = src.Name;
	this->hit_points = src.hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << BLUE << "copy Constructor Called"<< RESET << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << BLUE << "ClapTrap Destructor Called" << BLUE << std::endl;
}

void	ClapTrap::takeDammage(unsigned int amount)
{
	std::cout << YELLOW << this->Name << RED << " get damaged by : " << amount << " Damage Points" <<  RESET << std::endl;
	if (amount > (unsigned int)this->hit_points)
	{
		this->hit_points = 0;
		return ;
	}
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0)
	{
		std::cout<< YELLOW << this->Name << RED << "is dead" << std::endl;
		return ;
	}
	if (Energy_points == 0)
		return ;
	hit_points += amount;
	std::cout << GREEN << this->Name << " get repairs itself by : " << amount << std::endl;
	this->Energy_points--; 
}
