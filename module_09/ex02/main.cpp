# include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    PmergeMeList    ListEngine;
    try
    {
        if (ac < 2)
        {
            std::cerr << "Error : provide the sequence of numbers" << std::endl;
            return (1);
        }
        ListEngine.Collect_sequence(ac, av);
        // sort_engine.split_args(av, ac - 1);
        // sort_engine.display_pairs();
        // sort_engine.display_winners_losers();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);    
}
