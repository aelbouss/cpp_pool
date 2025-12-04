#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include  <iostream>

class HumanA
{
    private:
        Weapon  &weapon;
        std::string Name;
    public:
        void    attack(void);
        HumanA(std::string name , Weapon& wpn);
        ~HumanA();
};  

#endif