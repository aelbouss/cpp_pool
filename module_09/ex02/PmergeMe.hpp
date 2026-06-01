# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <queue>
# include <cstdlib>


class   PmergeMe
{
    private:
        std::vector<std::pair<int, int> >    container;
    public:

        void    assign_pair(int n1, int n2);
        void    display_pairs();
        void    split_args(char **av, int ac);
        PmergeMe();
        PmergeMe&   operator = (const PmergeMe& src);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe();
};


bool    is_even(int args_num);


# endif
