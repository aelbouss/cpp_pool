# include "PmergeMe.hpp"

int     main(int ac, char **av)
{   


        if (ac < 2)
        {
            std::cerr << "Error : provide the sequence of numbers" << std::endl;
            return (1);
        }

        {
        try
        {
           
            PmergeMeList    ListEngine(ac, av);
            struct timespec  start , end;

            std::cout << RED << "Before:  " << RESET;
            for (int i = 1 ; i < ac ; i++)
            {
                std::cout << RED << av[i] << RESET ;
                if (i < ac)
                    std::cout << " ";
            }
            std::cout << '\n';

            clock_gettime(CLOCK_MONOTONIC, &start);
            std::list<Element *> ll =  ListEngine.recrusive_sort(ListEngine.get_container());
            clock_gettime(CLOCK_MONOTONIC, &end);
            std::cout << GREEN << "After:   " << RESET;
            for (std::list<Element *>::iterator it = ll.begin() ; it != ll.end() ; ++it)
                std::cout << GREEN << (*it)->nbr << RESET << " ";
            std::cout << std::endl;
            double seconds = end.tv_sec - start.tv_sec;
            double nanoseconds = end.tv_nsec - start.tv_nsec;
            double time_ms = (seconds * 1000.0) + (nanoseconds / 1000000.0);
            std::cout << YELLOW << "Time to process a range of   " << ac -1 << " elements with std::[List] : " << time_ms << " us" << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try
        {
            PmergeMeVector  VectorEngine(ac, av);
            struct timespec  start , end;

            std::cout << RED << "Before:  " << RESET;
            for (int i = 1 ; i < ac ; i++)
            {
                std::cout << RED << av[i] << RESET ;
                if (i < ac)
                    std::cout << " ";
            }
            std::cout << '\n';
                clock_gettime(CLOCK_MONOTONIC, &start);
            std::vector<Element *> ll =  VectorEngine.recrusive_sort(VectorEngine.get_vect_container());
            clock_gettime(CLOCK_MONOTONIC, &end);
            std::cout << GREEN << "After:   " << RESET;
            for (size_t i = 0 ; i < ll.size() ; i++)
            {
                std::cout << GREEN << ll[i]->nbr << RESET << ' ';
            }
            std::cout << std::endl;
            double seconds = end.tv_sec - start.tv_sec;
            double nanoseconds = end.tv_nsec - start.tv_nsec;
            double time_ms = (seconds * 1000.0) + (nanoseconds / 1000000.0);
            std::cout << YELLOW << "Time to process a range of   " << ac -1 << " elements with std::[VECTOR] : " << time_ms << " us" << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
      

    }
    return (0);    
}