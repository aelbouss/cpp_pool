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
    pairs.push_back(std::make_pair(n1, n2));
}

void    PmergeMe::display_pairs()
{
    for (size_t i = 0 ; i < pairs.size() ;i++)
         std::cout << "{" << pairs[i].first << ", " << pairs[i].second << "}" << std::endl;
}

void    PmergeMe::split_args(char **av, int ac)
{
    int n1;
    int n2;

    for (size_t i = 1 ; (int)i < ac ; i+= 2)
    {
        if ((int)(i) < ac)
        {
            n1 = atoi(av[i]);
            n2 = atoi(av[i + 1]);
            if (n1 > n2)
            {
                assign_pair(n1, n2);
                fill_winners(n1);
                fill_losers(n2);
            }
            else
            {
                assign_pair(n2, n1);
                fill_winners(n2);
                fill_losers(n1);
            }
        }
    }
    if (!is_even(ac))
        std::cout << "The Left one is : "  << av[ac] << std::endl;
    std::sort(pairs.begin(), pairs.end());
}

void    PmergeMe::fill_winners(int nb)
{
    winners_list.push_back(nb);
}

void    PmergeMe::fill_losers(int nb)
{
    losers_list.push_back(nb);
}

void    PmergeMe::display_winners_losers(void)
{
    std::cout << RED << "Winners List" << RESET << std::endl;
    std::cout << YELLOW << "{" << RESET ;
    for (size_t i = 0 ; i < winners_list.size() ; i++)
    {
        std::cout << winners_list[i] ;
        if (i < (winners_list.size()-1))
            std::cout << ", " ;
    }
    std::cout << YELLOW << "}" << RESET << std::endl;
    std::cout << GREEN << "Losers List" << RESET << std::endl;
    std::cout << YELLOW << "{" << RESET ;
    for (size_t i = 0 ; i < losers_list.size() ; i++)
    {
        std::cout << losers_list[i] ;
        if (i < (losers_list.size() -1 ))
            std::cout << ", " ;
    }
    std::cout << YELLOW << "}" << RESET << std::endl;
}

PmergeMe::PmergeMe(){}
PmergeMe&   PmergeMe::operator = (const PmergeMe& src) { (void)src; return *this;}
PmergeMe::PmergeMe(const PmergeMe& src) { (void)src;}
PmergeMe::~PmergeMe(){}
