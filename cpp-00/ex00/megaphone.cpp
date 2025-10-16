#include <iostream>

int	main(int ac, char *argv[])
{
	std::string	str;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	j = 1;
	while(argv[j])
	{
		str = argv[j];
		for(size_t i = 0 ; i < str.length() ; i++)
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32 ;
		std::cout << str; 
		j++;	
	}
	std::cout << "\n"<<std::endl;
	return (0);
}
