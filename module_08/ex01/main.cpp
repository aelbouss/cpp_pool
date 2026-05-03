# include "Span.hpp"


int		main(void)
{
	Span	sp = Span(1000);
	Span	sp2(5);

	try
	{
		
		{
			for(int i = 0 ; i < 1000; i++)
				sp.addNumber(i+i);
			std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
			std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
		}

			std::cout << "====================" << std::endl;
		{
			std::vector<int> vec;
			vec.push_back(6);
			vec.push_back(3);
			vec.push_back(17);
			vec.push_back(9);
			vec.push_back(11);
			std::vector<int>::iterator begin = vec.begin();
			std::vector<int>::iterator end = vec.end();
			sp2.addnNmbers(begin, end);
			std::cout << "Longest Span : " << sp2.longestSpan() << std::endl;
			std::cout << "Shortest Span : " << sp2.shortestSpan() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}