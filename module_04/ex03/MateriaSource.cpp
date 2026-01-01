# include  "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0 ; i < 4 ; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if ( this->inventory[i] != NULL)
            this->inventory[i] = src.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}


MateriaSource& MateriaSource::operator = (const MateriaSource& src)
{
    if (this == &src)
        return (*this);     
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->inventory[i] != NULL)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL ;
        }
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (src.inventory[i] != NULL)
            this->inventory[i] = src.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        std::cerr << "invalid Materia !" << std::endl;
        return ;
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (inventory[i] != NULL && inventory[i]->getType() == type)
            return (inventory[i]->clone());
    }
    return (NULL);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (inventory[i] != NULL)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}
