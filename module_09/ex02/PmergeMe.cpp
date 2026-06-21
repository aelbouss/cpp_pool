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

bool compare_elements(Element *a, Element *b)
{
    return a->nbr < b->nbr;
}

std::list<Element *> PmergeMeList::recrusive_sort(std::list<Element *> l)
{
    std::list<Element *>    winners;
    Element                 *straggler =    NULL;
    std::list<Element *>    pend;
    iter    end_s;

    if (l.size() % 2 != 0)
    {
        iter last =  l.end();
        --last;
        straggler = *last;
        end_s = l.end();
        --end_s;
    }
    else
        end_s = l.end();
    iter it = l.begin();
    while (it != end_s)
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
    if (winners.size() > 1)
        recrusive_sort(winners);

    for (iter it = winners.begin() ; it != winners.end(); ++it)
    {
        if (!(*it)->defeated.empty())
        {
            Element *p =  (*it)->defeated.back();
            (*it)->defeated.pop_back(); 
            pend.push_back(p);
        }
    }
    Element *p = pend.front();
    pend.pop_front();
    winners.push_front(p);
    if (straggler != NULL)
    {
        iter it = std::lower_bound(winners.begin(), winners.end(), straggler, compare_elements); 
        winners.insert(it, straggler);  
    }
    return winners ;
}