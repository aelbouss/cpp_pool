# include  "Character.hpp"

Character::Character() {}

 Character::Character(std::string Name) : name(Name) 
 {
    for(int i = 0 ; i < 4 ; i++)
        spells_book[i] = NULL ;
 }

Character&  Character::operator = (const Character& src)
{
    if (this == &src)
        return (*this);
    for (int i = 0; i < 4 ; i++)
    {
        delete this->spells_book[i];
        this->spells_book[i] = NULL;
    }
    this->name = src.getName();
     for(int i = 0; i < 4 ; i++)
        this->spells_book[i] =  src.spells_book[i]->clone();
    return (*this);
}

Character::Character(const Character& src)
{
    for(int i = 0; i < 4 ; i++)
        this->spells_book[i] =  src.spells_book[i]->clone();
}


std::string const&  Character::getName()const { return (name); }


void    Character::equip(AMateria  *materia)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if (spells_book[i] == NULL)
            spells_book[i] = materia;
    }
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cerr << "invalid index to unequipe " << std::endl;
        return ;
    }
    if (spells_book[idx] != NULL)
        spells_book[idx] = NULL ;
}

void   Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "invalid index to use" << std::endl;
        return ;
    }
    if (spells_book[idx] != NULL)
        spells_book[idx]->use(target);               
}

Character:: ~Character()
{
    // for(int i = 0 ; i < 4 ; i++)
    // {
        // if (spells_book[i] != NULL)
        // {
            // delete spells_book[i];
            // spells_book[i] = NULL;
        // }
    // }
}