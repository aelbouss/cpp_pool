# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <cstdlib>
# include <ctime>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(int Grade, std::string Name);
		Bureaucrat& operator = (const Bureaucrat& src);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		std::string	getName(void)const;
		int	getGrade(void) const;
		void	increment(void);
		void	decrement(void);
		void	signForm(AForm& f, Bureaucrat& b);
		friend	std::ostream&	operator << (std::ostream& os, const Bureaucrat& b);
		void	executeForm(AForm const &form) const;
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\e[0;34m"
# define RESET "\033[0m"

# endif
