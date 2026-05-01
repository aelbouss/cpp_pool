# include "array.hpp"
# include "ArrayException.hpp"

int	main(void)
{
	try
	{
		array<int> intarr(5);
		array<std::string>strs(3);
		array<float>floats(1); 

		for (int i = 0 ; i  <  intarr.get_size() ; i++)
			intarr[i] = i+1;
		for (int i = 0 ; i <  intarr.get_size() ; i++)
			std::cout << intarr[i] << std::endl;
		strs[0] = "winners";
		strs[1] = "2005";
		strs[2] = "per la vita";
		for (int i = 0 ; i <  strs.get_size() ; i++)
			std::cout << strs[i] << std::endl;
		floats[1] = 1.5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;	
}