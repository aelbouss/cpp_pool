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


std::vector<size_t> generate_jacobstal_indexes(std::list<Element*>& pend_list)
{
    size_t size = pend_list.size();
    std::vector<size_t>    jacobstal_idxes;
    jacobstal_idxes.push_back(1);
    jacobstal_idxes.push_back(3);
    while (jacobstal_idxes.size() < size)
    {
        size_t  next = jacobstal_idxes[jacobstal_idxes.size() -1] + 2 * jacobstal_idxes[jacobstal_idxes.size() - 2] ;
        jacobstal_idxes.push_back(next);
    }
    return jacobstal_idxes;
}

std::vector<Element *>  turn_list_into_vector(std::list<Element*>& pend_list)
{
    iter    it = pend_list.begin();
    std::vector<Element *>    list;
    while (it !=  pend_list.end())
    {
        list.push_back(*it);
        ++it;
    }
    return list;
}

void jacobstal_binary_insertion(std::list<Element*>& winners, std::list<Element*>& pend_list)
{
    if (pend_list.empty())
        return;
    std::vector<Element*> pend_vec = turn_list_into_vector(pend_list);
    winners.push_front(pend_vec[0]);
    if (pend_vec.size() == 1)
        return;
    std::vector<size_t> jacob_seq = generate_jacobstal_indexes(pend_list);
    size_t last_boundary = 0; 

    for (size_t k = 1; k < jacob_seq.size(); ++k)
    {
        size_t upper_boundary = jacob_seq[k] - 1;
        if (upper_boundary >= pend_vec.size())
            upper_boundary = pend_vec.size() - 1;
        for (long i = static_cast<long>(upper_boundary); i > static_cast<long>(last_boundary); --i)
        {
            Element* pending_loser = pend_vec[i];
            Element* its_winner = pending_loser->partner;
            iter partner_iter = std::find(winners.begin(), winners.end(), its_winner);
            iter insert_slot = std::lower_bound(winners.begin(),  partner_iter, pending_loser, compare_elements);
            winners.insert(insert_slot, pending_loser);
        }
        last_boundary = upper_boundary;
    }
}


std::list<Element *> PmergeMeList::recrusive_sort(std::list<Element *> l)
{
    std::list<Element *>    winners;
    Element                 *straggler =    NULL;
    std::list<Element *>    pend_list;
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
            second->partner = first;
            winners.push_back(first);
        }
        else
        {
            second->defeated.push_back(first);
            first->partner = second;
            winners.push_back(second);
        }
        if (it == l.end())
            break ;
        std::advance(it, 2);
    }
    if (winners.size() > 1)
       winners = recrusive_sort(winners);
    /*extract the losers from the winners pockets into the pend list*/  
    for (iter it = winners.begin(); it != winners.end(); ++it)
    {
        if (!(*it)->defeated.empty())
        {
            Element *p = (*it)->defeated.back();
            (*it)->defeated.pop_back();
            pend_list.push_back(p);
        }
    }
    jacobstal_binary_insertion(winners, pend_list);
    if (straggler != NULL)
    {
        iter it = std::lower_bound(winners.begin(), winners.end(), straggler, compare_elements); 
        winners.insert(it, straggler);
    }
    return winners ;

}
