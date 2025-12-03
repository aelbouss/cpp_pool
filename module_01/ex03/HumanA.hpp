#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon  weapon;
        std::string Name;
    public:
        std::string get_name(void);
        void    set_name(std::string name);
        void    attack(void);
         HumanA(std::string name , Weapon wpn);
        HumanA(/* args */);
        ~HumanA();
};  
