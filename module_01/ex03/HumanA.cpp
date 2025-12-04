#include  "HumanA.hpp"
#include "Weapon.hpp"

void    HumanA::attack(void)
{
    std::cout << Name << " : attacks with their : " << weapon.getType() << std::endl;
}
HumanA::HumanA(std::string name , Weapon& wpn) :weapon(wpn) ,Name(name) {}

HumanA::~HumanA() {}