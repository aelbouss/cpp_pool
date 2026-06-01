# include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    PmergeMe    sort_engine;

    sort_engine.split_args(av, ac - 1);
    sort_engine.display_pairs();
    return (0);    
}
