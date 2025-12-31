# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include  "AMateria.hpp"
# include "ICharacter.hpp"

class   Character :public ICharacter
{
    private:
        AMateria    *spells_book[4];
        std::string name;
    public :
        Character();
        Character(std::string name);
        Character(const Character& src);
        Character&  operator = (const Character& src);
        ~Character();
        std::string const&  getName()const;
        void    equip(AMateria  *materia);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);

};

# endif