# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <queue>
# include <list>
# include <cstdlib>
# include <iterator>
# include <vector>
# include <algorithm>
# include <time.h>


    struct  Element
    {
        int nbr;
        std::list <Element*> defeated;
        Element *partner;
    };

    typedef std::list<Element *>::iterator  iter;
    
    class   PmergeMeList
    {
        private:
                std::list<Element *> container;
        public:
                PmergeMeList();
                PmergeMeList(int , char **av);
                PmergeMeList&   operator << (const PmergeMeList&  src);
                PmergeMeList(const PmergeMeList& src);
                ~PmergeMeList();

                std::list<Element *>    get_container();
                std::list<Element *> recrusive_sort(std::list<Element *>);
    };

    typedef std::vector<Element*>::iterator vec_iter;
    class   PmergeMeVector
    {
        private:
                std::vector <Element *> container;
        public:
                PmergeMeVector();
                PmergeMeVector(int, char **av);
                PmergeMeVector& operator << (const PmergeMeVector& src);
                PmergeMeVector(const PmergeMeVector& src);
                ~PmergeMeVector();

                std::vector<Element *>  get_vect_container();
                std::vector<Element *>  recrusive_sort(std::vector<Element *>);
 
    };

# define  RED "\e[0;31m"
# define  RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW	"\e[0;33m"

# endif
