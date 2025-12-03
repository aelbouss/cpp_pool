#include  "HumanB.hpp"
#include  "Weapon.hpp"

std::string    HumanB::get_name(void) { return (Name); }

void   HumanB::set_name(std::string name) { Name = name ; }

void    HumanB::attack(void)
{
    std::cout << get_name() << " : attacks with their : " << weapon.getType() << std::endl; 
}
void    setWeapon(std::string weapon)
{
}
HumanB::HumanB(std::string name) : Name(name){}

HumanB::HumanB() {}

HumanB::~HumanB() {}