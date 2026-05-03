# include "Span.hpp"

Span::Span() :N(0){}

Span::Span(unsigned int nb) :N(nb) {}

Span&	Span::operator = (const Span& src)
{
	if (this == &src)
		return *this;
	this->container = src.container;
	this->N = src.N;
	return *this;
}

Span::Span(const Span& src) { *this = src; }

Span::~Span() {}

void	Span::addNumber(int nb)
{
	if (this->container.size() < N)
	{
		this->container.push_back(nb);
		return ;
	}
	throw std::out_of_range("Error : Cannot Add Numbers");
}


unsigned int	Span::shortestSpan() const
{
	int	min;
	int val1 ;
	int val2 ;

	if (this->container.size() < 2)
		throw std::exception();
	
	for(size_t i = 0; i < this->container.size() ; i++)
	{
		for (size_t j = i + 1 ; j < this->container.size() ; j++)
		{
			val1 = container[i] - container[j];
			val2 = container[j] - container[i];
			if (val1 < min && val1 >= 0)
				min = val1;
			if(val2 < min && val2 >= 0)
				min = val2;
		}
	}
	return min;
}

unsigned int	Span::longestSpan() const 
{
	if (this->container.size() < 2)
		throw std::exception();
	std::vector<int>::const_iterator max = std::max_element(this->container.begin(), this->container.end());
	std::vector<int>::const_iterator min = std::min_element(this->container.begin(), this->container.end());
	return (*max - *min);
}

