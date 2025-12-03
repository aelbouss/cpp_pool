#include  "HumanA.hpp"
#include "Weapon.hpp"

void    HumanA::set_name(std::string name) { Name = name; }

std::string HumanA::get_name(void) { return (Name); }

void    HumanA::attack(void)
{
    std::cout <<  get_name() << " : attacks with their : " << weapon.getType() << std::endl;
}
HumanA::HumanA(std::string name , Weapon wpn): Name(name) , weapon(wpn) {}
HumanA::HumanA() {}

HumanA::~HumanA() {}