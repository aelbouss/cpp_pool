# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include  "AMateria.hpp"

class   Character
{
    private:
        AMateria    *inventory[4];
        std::string name;
    public :
        Character();
        Character(const Character& src);
        Character&  operator = (const Character& src);
        ~Character();
        Character(std::string const &name);
        std::string const&  getName()const;
        void    equip(AMateria  *materia);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);

};

# endif