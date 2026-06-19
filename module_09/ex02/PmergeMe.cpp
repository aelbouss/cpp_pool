# include "PmergeMe.hpp"


PmergeMeList::PmergeMeList() {}
PmergeMeList&   PmergeMeList::operator << (const PmergeMeList&  src)
{
    if (this != &src)
        this->container = src.container;
    return (*this);
}

PmergeMeList::PmergeMeList(const PmergeMeList& src)
{
    *this = src;
}
PmergeMeList::~PmergeMeList(){}

void    PmergeMeList::Collect_sequence(int ac, char **av)
{
    int nbr1;
    int nbr2;
    for (int i = 1 ; i < ac ; i++)
    {
        nbr1 = atoi(av[i]);
        if (nbr1 < 0)
            throw std::runtime_error("Error : Negative Number");
        nbr2 = atoi(av[i + 1]);
         if (nbr2 < 0)
            throw std::runtime_error("Error : Negative Number");
        Element *unit = new Element();
        std::list<Element *>winners;
        if (nbr1 > nbr2)
        {
            unit->nbr = nbr1;
            unit->defeated.push_back(nbr2);
        }
        else
        {
            unit->nbr = nbr2;
            unit->defeated.push_back(nbr1);
        }
        winners.push_back(unit);
    }

}

std::list<Element *>    rec_sort(std::list<Element *> l)
{
    if (l.size() > 1)
    {
        std::list<Element *> winners;
        std::list<Element *>::iterator it = l.begin();
        while (it != l.end())
        {
            Element *unit = new()
            if (it->nbr < (it + 1)-> nbr)
            {
                unit->
            }
        } 
    }
}

