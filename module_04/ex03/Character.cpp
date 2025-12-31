# include  "Character.hpp"

Character::Character()
{
    std::cout << "Character's Default Constructor Called" << std::endl;
}

Character&  Character::operator = (const Character& src)
{

}

Character::Character(const Character& src)
{
    std::cout << "Character's Copy Constructor Called" << std::endl;
}

std::string const&  Character::getName()const { return (name); }

void    Character::equip(AMateria  *materia)
{

}

void    Character::unequip(int idx)
{
  
}

void   Character::use(int idx, ICharacter& target)
{

}

Character:: ~Character()
{
    std::cout << "Character's Destructor Called" << std::endl;
}