# ifndef DOG_HPP
# define DOG_HPP


# include "AAnimal.hpp"
# include "Brain.hpp"


class Brain;

class	Dog : public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog&	operator = (const Dog& src);
		Dog(const Dog& src);
		void	get_dog_ideas();
		virtual void	makeSound() const ;
		~Dog();
};

# endif