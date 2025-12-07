#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include  <iostream>

class HumanA
{
    private:
        Weapon  &weapon;
        std::string name;
    public:
        void    attack(void);
        HumanA(std::string name , Weapon& wpn);
        ~HumanA();
};  

#endif