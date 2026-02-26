# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include  <iostream>
# include <exception>
# include "AForm.hpp"

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
		// exceptions nested classes
		class	GradeTooHighException :public std::exception
		{
			private:
				int	grade;
			public:
				GradeTooHighException(int grade);
				virtual ~GradeTooHighException() throw();
				std::string	what();
		};

		class GradeTooLowException
		{
			private:
				int	grade;
			public:
				GradeTooLowException(int Grade);
				virtual ~GradeTooLowException() throw();
				std::string	what();
		};
};

std::ostream&	operator << (std::ostream& os, const Bureaucrat& b);

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# endif
