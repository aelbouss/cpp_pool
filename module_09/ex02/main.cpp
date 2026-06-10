# include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    PmergeMe    sort_engine;

    sort_engine.split_args(av, ac - 1);
    sort_engine.display_pairs();
    sort_engine.display_winners_losers();
    return (0);    
}

// i need  to  separate the  winners and the  losers .
