# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include  <iostream>
# include <exception>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "Form.hpp"

class Form;

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
		void	signForm(Form& f, Bureaucrat& b);
		friend	std::ostream&	operator << (std::ostream& os, const Bureaucrat& b);
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# endif
