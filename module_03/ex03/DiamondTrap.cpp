# include  "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->Name = "Nothing";
    this->hit_points = 0;
    this->Energy_points = 0;
    this->Attack_damage = 0;
    std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") , ScavTrap(name) , FragTrap(name)
{
    this->Name = name;
    this->hit_points = FragTrap::hit_points;
    this->Energy_points = ScavTrap::Energy_points;
    this->Attack_damage = FragTrap::Attack_damage;
    std::cout << BLUE << "DiamondTrap Parameterized Constructor Called"<< RESET << std::endl;
}

 DiamondTrap&   DiamondTrap::operator = (const DiamondTrap& src)
{
    if (this == &src)
        return (*this);
    std::cout << "DiamondTrap Copy Assignment Called " << std::endl;
    this->Name = src.Name;
    this->hit_points = src.hit_points;
    this->Energy_points = src.Energy_points;
    this->Attack_damage = src.Attack_damage;
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src) , ScavTrap(src) , FragTrap(src)
{
    std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << BLUE << "DiamondTrap's Destructor Called" << RESET << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << GREEN << "Hello i'm DiamondTrap : " << Name << " and This is Claptrap : " << ClapTrap::Name << RESET << std::endl;
}