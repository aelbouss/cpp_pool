#include  "HumanA.hpp"
#include "Weapon.hpp"

void    HumanA::attack(void)
{
    std::cout << name << " : attacks with their : " << weapon.getType() << std::endl;
}
HumanA::HumanA(std::string name , Weapon& wpn) :weapon(wpn) ,name(name) {}

HumanA::~HumanA() {}