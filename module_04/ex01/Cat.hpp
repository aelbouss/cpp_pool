# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp" 

class Brain;

class	Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat&	operator = (const Cat& src);
		Cat(const Cat& src);
		void	get_cat_ideas();
		void	makeSound() const ;
		~Cat();
};

# endif