# include  "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain's Constructor Called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	for(int i = 0 ; i < 100 ; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "Brain's Copy Constructor Called" << std::endl;
}
Brain&	Brain::operator = (const Brain& src)
{
	if (this == &src)
		return (*this);
	std::cout << "Brain's Copy Assignment Operator Called" << std::endl;
	for(int i = 0 ; i < 100 ; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain's Destructor Called" << std::endl;
}