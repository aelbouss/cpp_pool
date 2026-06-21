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
        std::list<Element *> ll =  ListEngine.recrusive_sort(ListEngine.get_container());
        std::cout << "Sorted Sequence : " ;
        for (std::list<Element *>::iterator it = ll.begin() ; it != ll.end() ; ++it)
            std::cout << (*it)->nbr << " ";
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);    
}