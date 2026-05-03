# ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iterator>
# include <vector>
# include <exception>
# include <algorithm>

class	Span
{
	private:
		std::vector<int> container;
		unsigned int N;
	public:
		Span();
		Span(unsigned int nb);
		Span&	operator = (const Span& src);
		Span(const Span& src);
		~Span();
		void	addNumber(int value);
		unsigned int		shortestSpan() const ;
		unsigned int		longestSpan() const ;


		template <typename ADD>
		void addnNmbers(ADD begin, ADD end)
		{
			unsigned int dst = std::distance(begin, end);
			if (container.size() + dst > N)
				throw std::out_of_range("Error : run outside the container range");
		    container.insert(container.begin(), begin, end);
		}
};

# endif