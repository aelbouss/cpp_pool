# ifndef easyfind_hpp
# define easyfind_hpp

# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>

template <typename T>

void	easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
	{
		std::cout << "the value : " << value << " exists" << std::endl;
		return ;
	}
	throw std::exception();
}

# endif