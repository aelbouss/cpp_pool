# include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    try
    {
        if (ac < 2)
        {
            std::cerr << "Error : provide the sequence of numbers" << std::endl;
            return (1);
        }
        PmergeMeList    ListEngine(ac, av);
        ListEngine.display_container();
        //ListEngine.recrusive_sort(ListEngine.get_container());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);    
}