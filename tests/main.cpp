#include <iostream>
#include <string>

int	main(void)
{
	std::string str;
	std::string substr;
	std::string newstr;
	size_t	pos;
	
	str = "the winners 2005 winners per la winners vita";
	substr = "winners";
	newstr = "leet boys";
	pos = 0;
	while ((pos = str.find(substr, pos)) !=  std::string::npos)
	{
		str.erase(pos, substr.length());
		str.insert(pos, newstr);
		pos++;
	}
	std::cout << str; 
	return (0);
}
