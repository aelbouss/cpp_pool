# ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP

# include "Bureaucrat.hpp"

class GradeTooLowException
{
	private:
		int	grade;
	public:
		GradeTooLowException(int Grade);
		virtual ~GradeTooLowException() throw();
		std::string	what();
};


# endif
