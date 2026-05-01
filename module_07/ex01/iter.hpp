# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>


template	<typename T, typename F>
void	func(T	*arr, const size_t len ,  F worker)
{
	for (size_t i = 0 ; i <  len ; i ++)
	{
		worker(arr[i]);
	}
}

# endif