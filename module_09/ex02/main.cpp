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

        gettimeofday(&start_time, NULL);
        std::list<Element *> ll =  ListEngine.recrusive_sort(ListEngine.get_container());
        gettimeofday(&end_time, NULL);
        long seconds = end_time.tv_sec - start_time.tv_sec;
        long microseconds = end_time.tv_usec - start_time.tv_usec;
        double total_us = (seconds * 1000000.0) + microseconds;
        std::cout << "time to  process a range of   "<< ac -1 << " elements with std::[List]  :   " << total_us << " us" << std::endl ;

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