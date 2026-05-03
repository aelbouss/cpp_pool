# include "easyfind.hpp"
# include <vector>
# include <list>


int	main(void)
{
	std::vector <int> intv;
	std::list <int> intl;

	intv.push_back(1);
	intv.push_back(2);
	intv.push_back(3);

	intl.push_back(7);
	intl.push_back(8);
	intl.push_back(9);

	try
	{
		easyfind(intl, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << "the value doesn't exists within the list" << '\n';
	}

	try
	{
		easyfind(intv, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << "the value doesn't exists within the vector" << '\n';
	}


	std::cout << "the fail cases" << std::endl;


	try
	{
		easyfind(intl, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "the value doesn't exists within the list" << '\n';
	}

	try
	{
		easyfind(intv, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << "the value doesn't exists within the vector" << '\n';
	}
}