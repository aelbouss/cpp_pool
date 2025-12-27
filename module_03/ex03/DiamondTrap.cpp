# include  "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name") , ScavTrap(name) , FragTrap(name)
{
    this->name = name;
    hit_points = FragTrap::hit_points;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout << BLUE << "DiamondTrap Constructor Called"<< RESET << std::endl;
}

 DiamondTrap&   DiamondTrap::operator = (const DiamondTrap& src)
{
    if (this == &src)
        return (*this);
    std::cout << "DiamondTrap Copy Assignment Called " << std::endl;
    this->name = src.name;
    this->hit_points = src.hit_points;
    this->Energy_points = src.Energy_points;
    this->Attack_damage = src.Attack_damage;
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) :ClapTrap(src) , ScavTrap(src) , FragTrap(src)
{
    std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "the DiamondTrap Destructor Called" << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << GREEN << "Hello i'm DiamondTrap : " << name << RESET << std::endl;
}