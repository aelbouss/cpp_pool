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
        std::cout << (**it).nbr ;
        if ((**it).defeated.size() == 0)
            std::cout << "   => [] " << std::endl;
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
    std::list<Element *>    winners;
    iter it = l.begin();

    while (it != l.end())
    {
       
        iter next = it;
        ++next;
        if (next == l.end())
        {
            winners.push_back(*it);
            break ;
        }
        Element *first = *it;
        Element *second = *next;
        if (first->nbr > second->nbr)
        {
            first->defeated.push_back(second);
            winners.push_back(first);
        }
        else
        {
            second->defeated.push_back(first);
            winners.push_back(second);
        }
      
        if (it == l.end())
            break ;
        std::advance(it, 2);
    }

    for (iter it = winners.begin() ; it != winners.end() ; ++it)
    {
        std::cout << GREEN << "winner : " <<  (*it)->nbr ;
        if (!(*it)->defeated.empty())
        {
            Element *unit = (**it).defeated.back();
            std::cout << RED << "  => defeated : " << unit->nbr << RESET << std::endl;
        }
    }
    return winners ;
}


