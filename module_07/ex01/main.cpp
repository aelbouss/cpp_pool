# include "iter.hpp"


void	display(int const &n)
{
	std::cout << n << " " << std::endl;
}

void	make_strings_upper(std::string str)
{
	for (size_t i = 0 ; i < str.size() ; i++)
		std::cout << (char)std::toupper(str[i]) ;
	std::cout << "\n" << std::endl;
}

int	main(void)
{

	 const int	arr[] = {1, 2 , 3, 4};

	std::string strs[] = {"anass", "noon", "winners"};

	func(arr, 4, display);
	func(strs, 3, make_strings_upper);

	return (0);
}