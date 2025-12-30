# ifndef CAT_HPP
# define CAT_HPP

#include  "Animal.hpp"
# include "AAnimal.hpp"
# include "Brain.hpp" 

class Brain;

class	Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat&	operator = (const Cat& src);
		Cat(const Cat& src);
		void	get_cat_ideas();
		virtual void	makeSound() const ;
		~Cat();
};

# endif