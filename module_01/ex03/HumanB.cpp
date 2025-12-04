#include  "HumanB.hpp"
#include  "Weapon.hpp"

void    HumanB::attack(void)
{
    if (!weapon)
    {
        std::cerr << Name << " : doesnt have weapon !" << std::endl;
        return ;
    }
    std::cout << Name << " : attacks with their : " << weapon->getType() << std::endl; 
}
void    HumanB::setWeapon(Weapon &wpn)
{
     weapon = &wpn;
}
HumanB::HumanB(std::string name) : Name(name){}

HumanB::~HumanB() {}