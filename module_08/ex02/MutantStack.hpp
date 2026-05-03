# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack :public std::stack<T>
{
	public:

		typedef typename std::stack<T>::container_type::const_iterator iterator;
		MutantStack() {};
		MutantStack&	operator = (const MutantStack& src)
		{
			if (this != &src)
				std::stack<T>::operator=(src);
			return *this;
		}

		MutantStack(const MutantStack& src) :std::stack<T>(src) {}
		~MutantStack(){}
		
		iterator	begin() const { return this->c.begin(); }
		iterator	end() const { return this->c.end(); }
};

# endif