#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char *argv[])
{
	std::string	str;
	int	j;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	j = 1;
	while(argv[j])
	{
		str = argv[j];
		for(size_t i = 0 ; i < str.length() ; i++)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
		j++;
	}
	std::cout << "\n"<<std::endl;
	return (0);
}