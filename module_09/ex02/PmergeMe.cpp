# include "PmergeMe.hpp"

/**
 * @brief checks if the number  of arguments odd of even
 * @param args_num the number of arguments
 * @return true if the args number even otherways false
*/


bool    is_even(int args_num)
{
    return ((args_num % 2 == 0));
}

void    PmergeMe::assign_pair(int n1, int n2)
{
    container.push_back(std::make_pair(n1, n2));
}

void    PmergeMe::display_pairs()
{
    for (size_t i = 0 ; i <  container.size() ;i++)
         std::cout << "{" << container[i].first << ", " << container[i].second << "}" << std::endl;
}

void    PmergeMe::split_args(char **av, int ac)
{
    for (size_t i = 1 ; (int)i < ac ; i+= 2)
    {
        if ((int)(i) < ac)
            assign_pair(atoi(av[i]), atoi(av[i + 1]));
    }
    if (!is_even(ac))
        std::cout << "The Left one is : "  << av[ac] << std::endl;
}


PmergeMe::PmergeMe(){}
PmergeMe&   PmergeMe::operator = (const PmergeMe& src) { (void)src; return *this;}
PmergeMe::PmergeMe(const PmergeMe& src) { (void)src;}
PmergeMe::~PmergeMe(){}
