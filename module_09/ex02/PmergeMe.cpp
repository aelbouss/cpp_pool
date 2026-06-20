# include "PmergeMe.hpp"


PmergeMeList::PmergeMeList() {}

PmergeMeList::PmergeMeList(int ac, char **av)
{
    int nbr;

    for (int i = 1 ; i < ac ; i++)
    {
        nbr = atoi(av[i]);
        if (nbr < 0)
            throw std::runtime_error("Error : The Program Only Accept Positive Numbers");
        Element *unit = new Element();
        unit->nbr = nbr;
        container.push_back(unit);
    }
}

void    PmergeMeList::display_container(void)
{
    std::list<Element*>::iterator it = container.begin();
    while (it != container.end())
    {
        std::cout << (**it).nbr << std::endl;
        it++;
    }
}

PmergeMeList&   PmergeMeList::operator << (const PmergeMeList&  src)
{
    if (this != &src)
    {
        std::list<Element *>::iterator  it = container.begin();
        while (it != container.end())
        {
            std::list<Element *>::iterator curr = it;
            it++;
            delete(*curr);
        }
        this->container = src.container;
    }
    return (*this);
}

PmergeMeList::PmergeMeList(const PmergeMeList& src)
{
    *this = src;
}
PmergeMeList::~PmergeMeList()
{
    std::list<Element *>::iterator  it = container.begin();
    while (it != container.end())
    {
        std::list<Element *>::iterator curr = it;
        it++;
        delete(*curr);
    }
}

std::list<Element *>    PmergeMeList::get_container()
{
    return container ;
}

std::list<Element *> PmergeMeList::recrusive_sort(std::list<Element *> l)
{
    if (l.size() > 1)
    {
        std::list<Element *> winners;
        iter  start = l.begin();
        iter  end = l.end();
        while (start != end)
        {
            if ( (*start)->nbr  > (*))
        }
    }
}


